#include <bits/stdc++.h> 

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList){
    visited[node] = true;

    for(int neighbour: adjList[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adjList);
        }
    }

    // Push in stack
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adjList;

    for(int i=0; i<e; i++){
        int a = edges[i][0];
        int b = edges[i][1];

        adjList[a].push_back(b);
    }

    vector<bool> visited(v);
    stack<int> s;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adjList);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// Using Kahn Algorithm
vector<int> topologicalSort2(vector<vector<int>> &edges, int v, int e){
    // Create Adjacent List
    unordered_map<int, list<int>> adjList;

    for(int i=0; i<e; i++){
        int a = edges[i][0];
        int b = edges[i][1];

        adjList[a].push_back(b);
    }

    vector<int> indegree(v,0);
    // Find indegree of all the nodes
    for(auto i: adjList){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // Push nodes with zero indegree into queue
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);   
        }
    }

    // Do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // Store ans
        ans.push_back(front);

        // neighbour indegree update
        for(int neighbour: adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }


    }

    return ans;
}
#include<bits/stdc++.h>
// Using BFS
bool isCyclicBFS( int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList){
    unordered_map<int, int> parent;
    
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour: adjList[frontNode]){
            if(visited[neighbour] == true && neighbour != parent[frontNode]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i, visited, adjList);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

// Using DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList){
    visited[node] = true;

    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if(cycleDetected){
                return true;
            }
        }else if(neighbour != parent){
            // Cycle detected
            return true;
        }
    }
    return false;
}

string cycleDetection2 (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

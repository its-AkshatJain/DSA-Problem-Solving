#include<bits/stdc++.h>
using namespace std;

// for directed graph with given adjacency List
void bfs(vector<vector<int>> &adjList,vector<bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        // Store frontNode into the answer
        ans.push_back(frontNode);

        for(auto i: adjList[frontNode]){
            if(!visited[i]){
               q.push(i);
               visited[i] = 1; 
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &e){
    // n -> no. of vertex
    // e -> Adjacency List
    vector<int> ans;
    vector<bool> visited(n, false);

    bfs(e, visited, ans, 0);

    return ans;
}

// for Un-directed graph
void prepareAdjList(unordered_map< int, vector<int>> &adjList, vector<vector<int>> &e){
    for(int i=0; i<e.size(); i++){
        int u = e[i][0];
        int v = e[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs2(unordered_map< int, vector<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        // visited[frontNode] = 1; 

        // Store frontNode into the answer
        ans.push_back(frontNode);


        for(auto i: adjList[frontNode]){
            if(!visited[i]){
               q.push(i);
               visited[i] = 1; 
            }
        }
    }
}

vector<int> bfsTraversal2(int n, vector<vector<int>> &e){
    // n -> no. of vertex
    unordered_map< int, vector<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, e);

    // In case of disconnected graph
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs2(adjList, visited, ans, i);
        }
    } 

    // printAdjMatrix(adjList,n);
    return ans;
}

int main() {
    // Number of vertices and edges
    int n, m;
    cin >> n >> m;


    // Input the edges
    vector<vector<int>> edges;  
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});  // Use push_back to add pairs of edges
    }

    // Perform BFS traversal
    vector<int> result = bfsTraversal2(n, edges);

    // Output the result
    for(int node : result){
        cout << node << " ";
    }

    return 0;
}
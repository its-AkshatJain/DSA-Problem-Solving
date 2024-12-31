#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
         vector<int> &component, int node){
    component.push_back(node);
    visited[node] = true;

    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}
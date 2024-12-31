#include <bits/stdc++.h>
#include <unordered_map>
void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, 
        unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adjList,
        vector<vector<int>> &result){

            visited[node] = true;
            disc[node] = low[node] = timer++;

            for(int nbr: adjList[node]){
                if(nbr == parent){
                    continue;
                }
                if(!visited[nbr]){
                    dfs(nbr, node, timer, disc, low, visited, adjList, result);
                    // while returning update low
                    low[node] = min(low[node], low[nbr]);

                    // Check bridge case
                    if(low[nbr] > disc[node]){
                        vector<int> ans;
                        ans.push_back(node);
                        ans.push_back(nbr);
                        result.push_back(ans);
                    }
                }else{
                    // Node is visited
                    // Back edge
                    low[node] = min(low[node], disc[nbr]);
                }
            }

        }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int> > adjList;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);  // discovery time for node
    vector<int> low(v);   // earliest possible time for node
    int parent = -1;
    unordered_map<int, bool> visited;

    vector<vector<int>> result;

    // DFS
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, visited, adjList, result);
        }
    }

    return result;
}
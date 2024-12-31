#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, 
    vector<int> &ap, vector<int> &visited, unordered_map<int, list<int>> &adjList, int timer){

        visited[node] = 1;
        disc[node] = low[node] = timer++;
        int child = 0;

        for(int nbr:  adjList[node]){
            if(nbr == parent){
                continue;
            }
            if(!visited[nbr]){
                dfs(nbr, node, disc, low, ap, visited, adjList, timer);
                // While returning
                low[node] = min(low[node], low[nbr]);

                // AP condition
                if(low[nbr] >= disc[node] && parent != -1){
                    ap[node] = 1;
                }
                child++;
            }else{
                // Neighbour visited
                // Back edge
                low[node] = min(low[node], disc[nbr]);
            }
            if(parent == -1 && child > 1){
                ap[node] = 1;
            }
        }
}

int main(){
    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    vector<int> ap(n,0);
    vector<int> visited(n,0);

    // Initialise the array
    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, disc, low, ap, visited, adjList, timer);
        }
    }

    cout<<"Articulation Point is: "<<endl;
    for(int i=0; i<n; i++){
        if(ap[i] != 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        // Direction = 0-> Undirected
        // Direction = 1-> Directed
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> ans(n);

    // Ans array will store all adjacent nodes
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        // As undirected graph
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);

        // entering neighbours
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

int main(){
    int n,m;
    cout<<"Enter the no. of nodes : "<<endl;
    cin>>n;
    cout<<"Enter the no. of edges : "<<endl;
    cin>>m;

    Graph<int> g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // Creating a Undirected Graph
        g.addEdge(u, v, 0);
    }
    // 0 1
    // 1 2
    // 1 3
    // 2 3
    // 3 4
    // 0 4

    g.printAdjList();

    return 0;
}
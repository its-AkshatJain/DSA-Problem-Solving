#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class Graph{
    public:
    int vertex;
    vector<vector<T>> adj;

    Graph(int n){
        this->vertex = n;
        adj = vector<vector<T>>(n, vector<T>(n,0));
    }

    void addEdge(T u, T v, bool direction){

        if(u > vertex || v > vertex){
            cout<<"Node Index does not exist"<<endl;
            return;
        }

        // Direction = 0-> Undirected
        // Direction = 1-> Directed
        adj[u][v] = 1;
        if(direction == 0){
            adj[v][u] = 1;
        }
    }

    void printAdjMatrix(){
        for(int i=0; i<vertex; i++){
            // cout<<i.first<<" -> ";
            for(int j=0; j<vertex; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n,m;
    cout<<"Enter the no. of nodes : "<<endl;
    cin>>n;
    cout<<"Enter the no. of edges : "<<endl;
    cin>>m;

    Graph<int> g(5);

    for(int i=0; i<m; i++){
        int u,v;1
        cin>>u>>v;
        // Creating a Undirected Graph
        g.addEdge(u, v, 0);
    }
    // 5 6

    // 0 1
    // 1 2
    // 1 3
    // 2 3
    // 3 4
    // 0 4

    g.printAdjMatrix();

    return 0;
}
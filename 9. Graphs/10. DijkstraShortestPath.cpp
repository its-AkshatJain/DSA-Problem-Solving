#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int, list<pair<int,int>>> adjList;
    // Create adjacent List
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    // Create distance array
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    // Create a set storing distance, node
    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
      // fetch top record
      auto top = *(st.begin());  

      int nodeDistance = top.first;
      int topNode = top.second;

      // remove top record
      st.erase(st.begin());

      for(auto neighbour: adjList[topNode]){
          if(nodeDistance + neighbour.second < dist[neighbour.first]){
              auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
             
              // If record found erase it
              if(record != st.end()){
                  st.erase(record);
              }

              // update Distance
              dist[neighbour.first] = nodeDistance + neighbour.second;
              // record push in set
              st.insert(make_pair(dist[neighbour.first], neighbour.first));
          }
      }
    }
    
    return dist;
}

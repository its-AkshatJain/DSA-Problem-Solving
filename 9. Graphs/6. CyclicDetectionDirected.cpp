#include<bits/stdc++.h>
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjlist){
  visited[node] = 1;
  dfsVisited[node] = 1;

  for(auto neighbour: adjlist[node]){
    if(!visited[neighbour]){
      bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adjlist);
      if(cycleDetected){
        return true;
      }
    }else if(dfsVisited[neighbour]){
        return true;
      }
  }
  dfsVisited[node] = false;
  return false;
  
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adjlist;
  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adjlist[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for(int i=0; i<n; i++){
    if(!visited[i]){
      bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adjlist);
      if(cycleFound){
        return true;
      }
    }
  }
  return false;
}



// Using BFS Kahns Algo
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adjlist;
  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adjlist[u].push_back(v);
  }

  vector<int> indegree(n,0);

  // Find indegree of all the nodes
  for(auto i: adjlist){
    for(auto j: i.second){
      indegree[j]++;
    }
  }

  // Push nodes with zero indegree into queue
  queue<int> q;
  for(int i=0; i<n; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }

  int cnt = 0;
  while(!q.empty()){
    int front = q.front();
    q.pop();

    // increment count
    cnt++;

    for(int neighbour: adjlist[front]){
      indegree[neighbour]--;
      if(indegree[neighbour] == 0){
          q.push(neighbour);
      }
    }
  }

  if(cnt == n){
    return false;
  }else{
    return true;
  }
  
  return false;
}
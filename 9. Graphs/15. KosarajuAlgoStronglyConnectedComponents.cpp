#include <bits/stdc++.h>

void topo(int node, vector<bool> &visited, stack<int> &s, 
			unordered_map<int, list<int>> &adjList){

	visited[node] = true;

	for(auto neighbour: adjList[node]){
		if(!visited[neighbour]){
			topo(neighbour, visited, s, adjList);
		}
	}

	// topo logic
	s.push(node);
}

void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose){
	visited[node] = true;

	for(auto neighbour: transpose[node]){
		if(!visited[neighbour]){
			dfs(neighbour, visited, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adjList;

	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}

	stack<int> s;
	vector<bool> visited(v, 0);

	// Step 1 : Topological sort
	for(int i=0; i<v; i++){
		if(!visited[i]){
			topo(i, visited, s, adjList);
		}
	}

	// Step 2 : Transpose 
	unordered_map<int, list<int>> transpose;

	for(int i=0; i<v; i++){
		visited[i] = false;
		for(auto neighbour: adjList[i]){
			transpose[neighbour].push_back(i);
		}
	}

	// Step 3 : DFS
	int count = 0;
	while(!s.empty()){
		int top = s.top();
		s.pop();
		if(!visited[top]){
			count++;
			dfs(top, visited, transpose);
		}
	}

	return count;
	
}
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	void _dfs(int u,vector <int> adj[],vector <int> &visited,stack <int> &st){
		visited[u]=true;
		for(auto v:adj[u]){
			if(!visited[v]) _dfs(v,adj,visited,st);
		}
		st.push(u);
	}
public:
	vector<int> topoSortBFS(int V, vector<int> adj[])
	{
		//Kahn's Algorithm
		//Can be used to find cycle since if the graph contains cycle topo sorting would contain less than n nodes
		vector <int> indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}

public:
	vector <int> topoSortDFS(int V, vector <int> adj[]){
		stack <int> st;
		vector <int> vis(V,0);

		for(int i=0;i<V;i++){
			if(!vis[i]){
				_dfs(i,adj,vis,st);
			}
		}

		vector <int> topo;
		while(!st.empty()){
			topo.push_back(st.top());
			st.pop();
		}

		return topo;

		//We are pushing child nodes first, hence those nodes dependent on a particular node is pushed first
		//Hence when we extract it in the reverse order, it is in the topological sort order
	}
};

int main() {
	// create a graph with 5 vertices
	const int V = 5;
	vector<int> adj[V];

	// add edges to the graph
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(4);

	Solution sol;
	vector<int> topoBFS = sol.topoSortBFS(V, adj);
	vector<int> topoDFS = sol.topoSortDFS(V, adj);

	// print the topological sort
	for (int i : topoBFS) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : topoDFS) {
		cout << i << " ";
	}
	cout << endl;

	//Both are correct

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> topoSort(int V, vector<int> adj[])
	{
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
	vector<int> topo = sol.topoSort(V, adj);

	// print the topological sort
	for (int i : topo) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

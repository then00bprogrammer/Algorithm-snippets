#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

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

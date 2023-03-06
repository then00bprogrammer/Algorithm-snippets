#include <bits/stdc++.h>
using namespace std;

const int N = 100; // Maximum number of nodes
const int INF = 1e9; // Infinite capacity

int n, m; // Number of nodes and edges
vector<int> adj[N]; // Adjacency list representation
int cap[N][N]; 
int vis[N]; // Visited array to mark nodes as visited during DFS
int source, sink; // Source and sink nodes

// DFS to find augmenting path from source to sink
int dfs(int u, int curFlow, int limit) {
    if (u == sink) return curFlow;
    vis[u] = true;
    for (auto v : adj[u]) {
        int edgeCap = cap[u][v];
        if (edgeCap >= limit && !vis[v]) {
            int newFlow = dfs(v, min(curFlow, edgeCap), limit);
            if (newFlow > 0) {
                cap[u][v] -= newFlow;
                cap[v][u] += newFlow;
                return newFlow;
            }
        }
    }
    return 0;
}

// Compute max flow using capacity scaling
int max_flow() {
    int flow = 0;
    int limit = 1 << 30; // Start with a large limit
    while (limit > 0) {
        memset(vis, 0, sizeof(vis));
        while (int newFlow = dfs(source, INF, limit)) {
            flow += newFlow;
            memset(vis, 0, sizeof(vis));
        }
        limit >>= 1; // Reduce the limit by half
    }
    return flow;
}

int main() {
    // Define the graph
    n = 6;
    m = 9;
    source = 0;
    sink = 5;
    adj[source].push_back(1);
    adj[1].push_back(source);
    adj[source].push_back(2);
    adj[2].push_back(source);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(3);
    adj[4].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(4);
    cap[0][1] = 16;
    cap[0][2] = 13;
    cap[1][2] = 10;
    cap[1][3] = 12;
    cap[2][1] = 4;
    cap[2][4] = 14;
    cap[3][2] = 9;
    cap[3][5] = 20;
    cap[4][3] = 7;
    cap[4][5] = 4;
    source = 0;
    sink = 5;
    
    // Compute the maximum flow using DFS
    int mf = max_flow();
    cout << "Maximum flow: " << mf << endl;
    
    return 0;
}

/***
The Time Complexity of the Capacity Scaling algorithm is often given as O(E^2 log U), where U is the maximum capacity of an edge in the graph. This time complexity bound assumes that the scaling factor is chosen as 2, which is a common choice in practice.

To explain why the time complexity is O(E^2 log U), we can consider that in each iteration, the algorithm removes all edges whose capacities are less than the scaling factor. Therefore, the maximum capacity of an edge in the graph after k iterations is at most U/2^k.

The algorithm runs for k iterations until the maximum capacity of an edge is less than 2. Therefore, we have U/2^k < 2, which implies that k = log U.

In each iteration, the DFS algorithm is run on a graph with at most E edges whose capacities are at least 2^k. Therefore, the time complexity of each iteration is O(E).

The total time complexity of the Capacity Scaling algorithm is then O(kE) = O(E log U). However, the algorithm may need to run multiple times with different scaling factors until it finds the maximum flow. Therefore, the time complexity can be up to O(E^2 log U).

Note that the time complexity of the Capacity Scaling algorithm may vary depending on the scaling factor used, and it may not always be optimal for all graphs.
***/


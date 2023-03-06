#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n; // number of nodes
vector<vector<int>> cap; // capacity matrix
vector<int> level; // level of each node in the current BFS tree
vector<int> ptr; // pointer to the next outgoing edge to explore for each node

bool bfs(int s, int t) {
    level.assign(n, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (level[v] == -1 && cap[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[t] != -1;
}

int dfs(int u, int t, int flow) {
    if (u == t) {
        return flow;
    }
    for (int& i = ptr[u]; i < n; i++) {
        int v = i;
        if (level[v] == level[u] + 1 && cap[u][v] > 0) {
            int new_flow = min(flow, cap[u][v]);
            int pushed_flow = dfs(v, t, new_flow);
            if (pushed_flow > 0) {
                cap[u][v] -= pushed_flow;
                cap[v][u] += pushed_flow;
                return pushed_flow;
            }
        }
    }
    return 0;
}

int dinic(int source, int sink) {
    int max_flow = 0;

    while (bfs(source, sink)) {
        ptr.assign(n, 0);
        while (int flow = dfs(source, sink, INF)) {
            max_flow += flow;
        }
    }

    return max_flow;
}

int main() {
    n = 6;
    cap = {{0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    int source = 0;
    int sink = 5;

    int max_flow = dinic(source, sink);

    cout << "The maximum flow in the network is: " << max_flow << endl;

    return 0;
}

/***
 The time complexity of the Dinic's algorithm is O(V^2E) in the worst case, where V is the number of vertices and E is the number of edges in the graph. However, in practice, the algorithm performs much better than this worst-case bound and is considered to be one of the fastest maximum flow algorithms. When the graph has a specific structure, such as when it is a bipartite graph or a planar graph, the time complexity can be reduced to O(E * sqrt(V)).
 ***/
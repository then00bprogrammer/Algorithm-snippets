#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n; // number of nodes
vector<vector<int>> cap; // capacity matrix

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if (v == t) {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }

    return 0;
}

int edmonds_karp(int source, int sink) {
    int max_flow = 0;
    vector<int> parent(n);

    while (true) {
        int flow = bfs(source, sink, parent);
        if (flow == 0) {
            break;
        }
        max_flow += flow;
        int u = sink;
        while (u != source) {
            int v = parent[u];
            cap[v][u] -= flow;
            cap[u][v] += flow;
            u = v;
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

    int max_flow = edmonds_karp(source, sink);

    cout << "The maximum flow in the network is: " << max_flow << endl;

    return 0;
}

/***
In the worst case, the algorithm may have to run BFS V times, and each BFS takes O(E) time. Therefore, the time complexity is O(VE^2). However, in practice, the algorithm is much faster than the theoretical worst-case bound, and it is considered one of the fastest maximum flow algorithms.

Moreover, if the graph is sparse, i.e., E is much smaller than V^2, then the time complexity of the Edmonds-Karp algorithm becomes O(V^2E), which is the same as the time complexity of the Dinic's algorithm. Therefore, the Edmonds-Karp algorithm can be a good choice for sparse graphs.
***/

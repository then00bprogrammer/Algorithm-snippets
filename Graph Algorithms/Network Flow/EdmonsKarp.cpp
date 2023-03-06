#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class EdmondsKarp {
private:
    int n;
    vector<vector<int>> cap, flow;
    vector<int> parent;

    int bfs(int s, int t) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty()) {
            int u = q.front().first;
            int f = q.front().second;
            q.pop();

            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && cap[u][v] > flow[u][v]) {
                    parent[v] = u;
                    int new_f = min(f, cap[u][v] - flow[u][v]);
                    if (v == t) {
                        return new_f;
                    }
                    q.push({v, new_f});
                }
            }
        }
        return 0;
    }

public:
    EdmondsKarp(vector<vector<int>>& cap, vector<vector<int>>& flow) {
        n = cap.size();
        this->cap = cap;
        this->flow = flow;
        parent.resize(n);
    }

    void addEdge(int u, int v, int c) {
        cap[u][v] += c;
    }

    int computeMaxFlow(int s, int t) {
        int mf = 0;
        int new_f;
        while (new_f = bfs(s, t)) {
            mf += new_f;
            int u = t;
            while (u != s) {
                int v = parent[u];
                flow[v][u] += new_f;
                flow[u][v] -= new_f;
                u = v;
            }
        }
        return mf;
    }
};

int main() {
    int n = 6, m = 9;

    vector<vector<int>> cap(n, vector<int>(n, 0));
    vector<vector<int>> flow(n, vector<int>(n, 0));

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
    int source = 0;
    int sink = 5;

    EdmondsKarp mf(cap, flow);
    int maxFlow = mf.computeMaxFlow(source, sink);
    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}

/***
In the worst case, the algorithm may have to run BFS V times, and each BFS takes O(E) time. Therefore, the time complexity is O(VE^2). However, in practice, the algorithm is much faster than the theoretical worst-case bound, and it is considered one of the fastest maximum flow algorithms.

Moreover, if the graph is sparse, i.e., E is much smaller than V^2, then the time complexity of the Edmonds-Karp algorithm becomes O(V^2E), which is the same as the time complexity of the Dinic's algorithm. Therefore, the Edmonds-Karp algorithm can be a good choice for sparse graphs.
***/

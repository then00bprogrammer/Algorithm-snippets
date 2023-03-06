#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class FordFulkerson {
private:
    int n;
    vector<vector<int>> cap, flow;
    vector<bool> visited;

    int dfs(int u, int t, int f) {
        if (u == t) return f;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cap[u][v] > flow[u][v]) {
                int df = dfs(v, t, min(f, cap[u][v] - flow[u][v]));
                if (df > 0) {
                    flow[u][v] += df;
                    flow[v][u] -= df;
                    return df;
                }
            }
        }
        return 0;
    }
public:
    FordFulkerson(vector<vector<int>>& cap, vector<vector<int>>& flow) {
        n = cap.size();
        this->cap = cap;
        this->flow = flow;
        visited.resize(n);
    }

    void addEdge(int u, int v, int c) {
        cap[u][v] += c;
    }

    int computeMaxFlow(int s, int t) {
        int mf = 0;
        while (true) {
            fill(visited.begin(), visited.end(), false);
            int df = dfs(s, t, INF);
            if (df == 0) break;
            mf += df;
        }
        return mf;
    }

};

int main() {
    int n=6,m=9;

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

    FordFulkerson mf(cap, flow);
    int maxFlow = mf.computeMaxFlow(source, sink);
    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}

/***
 The Time Complexity of the Ford-Fulkerson algorithm using DFS to find augmenting paths is O(E * f), where E is the number of edges and f is the maximum flow in the graph. In the worst case, f can be as large as the capacity of the minimum cut in the graph, which is equal to the sum of the capacities of all edges in the minimum cut.

 Therefore, in the worst case, the time complexity of the Ford-Fulkerson algorithm using DFS is O(E * C), where C is the capacity of the minimum cut in the graph. This worst-case time complexity can make the algorithm inefficient for large graphs with high capacities. However, the Ford-Fulkerson algorithm can be improved by using a different method to find augmenting paths, such as the Edmonds-Karp algorithm or the Dinic's algorithm, which have better time complexities in practice.
 ***/

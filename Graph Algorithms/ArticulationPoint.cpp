#include <bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY : O(E+V) (DFS)
class ArticulationPointFinder {
private:
    int n;
    vector<int> *adj;
    int timer;
    vector<int> vis;
    int *tin;
    int *low;
    vector<int> articulationPoints;

    void tarjan(int node, int parent) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        ++timer;
        int children = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                tarjan(it, node);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                    articulationPoints.push_back(node);
                ++children;
            }
            else
                low[node] = min(low[node], tin[it]);
        }
        if (parent == -1 && children > 1)
            articulationPoints.push_back(node);
    }

public:
    ArticulationPointFinder(int numVertices, vector<int> adjacencyList[]) {
        n = numVertices;
        adj = adjacencyList;
        timer = 1;
        vis.resize(n + 1, 0);
        tin = new int[n + 1];
        low = new int[n + 1];
    }

    vector<int> findArticulationPoints() {
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0)
                tarjan(i, -1);
        }

        return articulationPoints;
    }
};

int main() {
    int n = 7;
    vector<int> adj[n + 1];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[6].push_back(7);
    adj[7].push_back(6);

//   1---2
//   |   |
//   3---4
//        |
//        5
//        |
//        6
//        |
//        7


    ArticulationPointFinder apf(n, adj);
    vector<int> articulationPoints = apf.findArticulationPoints();
    cout << "Articulation points in the graph:" << endl;
    for (int ap : articulationPoints) {
        cout << ap << endl;
    }

    return 0;
}

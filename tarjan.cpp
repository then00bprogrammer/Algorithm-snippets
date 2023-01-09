#include <bits/stdc++.h>
using namespace std;

class BridgeFinder {
private:
    int n;
    vector<int> *adj;
    int timer;
    vector<int> vis;
    int *tin;
    int *low;
    vector <vector<int>> bridges;

    void tarjan(int node, int parent) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        ++timer;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                tarjan(it, node);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                    bridges.push_back({it, node});
            }
            else
                low[node] = min(low[node], low[it]);
        }
    }

public:
    BridgeFinder(int numVertices, vector<int> adjacencyList[]) {
        n = numVertices;
        adj = adjacencyList;
        timer = 1;
        vis.resize(n + 1, 0);
        tin = new int[n + 1];
        low = new int[n + 1];
    }

    vector<vector<int>> findBridges() {
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0)
                tarjan(i, -1);
        }

        return bridges;
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
    //VISUALIZE HERE: `https://graphonline.ru/tmp/saved/yH/yHTxrmwpfwqrNOrQ.png`

    BridgeFinder bf(n, adj);
    vector<vector<int>> bridges = bf.findBridges();
    cout << "Bridges in the graph:" << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//O(E)
class EulerianPath {
private:
    vector<vector<int>> graph;

    void dfs(int u, vector<int>& euler_path) {
        while (!graph[u].empty()) {
            int v = graph[u].back();
            graph[u].pop_back();
            dfs(v, euler_path);
        }
        euler_path.push_back(u);
    }
public:
    EulerianPath(vector<vector<int>> adj) : graph(adj) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }

    vector<int> find_euler_path() {
        int n = graph.size();
        vector<int> in_degrees(n), out_degrees(n);
        int start_node = -1, end_node = -1;
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                in_degrees[v]++;
                out_degrees[u]++;
            }
        }
        for (int u = 0; u < n; u++) {
            if (in_degrees[u] + 1 == out_degrees[u]) {
                if (start_node != -1) {
                    return {};
                }
                start_node = u;
            } else if (in_degrees[u] == out_degrees[u] + 1) {
                if (end_node != -1) {
                    return {};
                }
                end_node = u;
            } else if (in_degrees[u] != out_degrees[u]) {
                return {};
            }
        }
        if (start_node == -1) {
            start_node = 0;
        }
        vector<int> euler_path;
        dfs(start_node, euler_path);
        reverse(euler_path.begin(), euler_path.end());
        return euler_path;
    }

};

int main() {
    int n = 7;
    vector<vector<int>> graph(n);
    graph[0] = {1,6};
    graph[1] = {2};
    graph[2] = {0,3};
    graph[3] = {4}; 
    graph[4] = {2,5};
    graph[5] = {0};
    graph[6] = {4};

    EulerianPath hierHolzer(graph);

    vector<int> euler_path = hierHolzer.find_euler_path();
    if (!euler_path.empty()) {
        cout << "Eulerian path: ";
        for (int i = 0; i < euler_path.size(); i++) {
            cout << euler_path[i];
            if (i != euler_path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "The EulerianPath does not have an Eulerian path." << endl;
    }

    return 0;
}

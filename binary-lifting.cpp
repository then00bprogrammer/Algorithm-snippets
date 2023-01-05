#include <bits/stdc++.h>
using namespace std;

class AncestryTree {
private:
    int n, height;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

public:
    AncestryTree(int num_nodes) {
        n = num_nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        height = ceil(log2(n));
        up.assign(n, vector<int>(height + 1));
        dfs(root, 0);
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= height; ++i)
            if (up[v][i-1] == -1) {
                up[v][i] = -1;
            }
            else {
                up[v][i] = up[up[v][i-1]][i-1];
            }

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }


    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = height; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    int getKthAncestor(int node, int k) {
        for(int lvl=0;lvl<height;lvl++){
            if(k&(1<<lvl)){
                node=up[node][lvl];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};

int main() {
    // Set up the tree
    AncestryTree tree(7);           
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);
    tree.addEdge(2, 6);

    //       0
    //      / \
    //     1   2
    //    / \ / \
    //   3  4 5  6

    // Preprocess the tree
    tree.preprocess(0);

    // Test the lca function
    int a = 3, b = 4;
    int c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 3 and 4 is 1"

    a = 3, b = 5;
    c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 3 and 5 is 0"

    a = 4, b = 5;
    c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 4 and 5 is 0"

    // Test the getKthAncestor function
    int node = 3, k = 1;
    int ancestor = tree.getKthAncestor(node, k);
    cout << "The " << k << "th ancestor of " << node << " is " << ancestor << endl; // should output "The 1th ancestor of 3 is 1"

    node = 3, k = 2;
    ancestor = tree.getKthAncestor(node, k);
    cout << "The " << k << "th ancestor of " << node << " is " << ancestor << endl; // should output "The 2th ancestor of 3 is 0"

    node = 3, k = 5;
    ancestor = tree.getKthAncestor(node, k);
    cout << "The " << k << "th ancestor of " << node << " is " << ancestor << endl; // should output "The 3th ancestor of 3 is -1" 
    //->to return -1 initialize up array to -1 instead of zero and comment out lca lines
    return 0;
}

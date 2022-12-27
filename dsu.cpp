#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

int main() {
    int n = 5; // Number of nodes
    DisjointSet dsu(n); // Create a disjoint set with n nodes

    // Merge nodes 1 and 2
    dsu.unionBySize(1, 2);

    // Merge nodes 3 and 4
    dsu.unionBySize(3, 4);

    // Merge nodes 2 and 3 (equivalent to merging nodes 1, 2, 3, and 4)
    dsu.unionBySize(2, 3);

    // Check if nodes 1 and 4 are in the same set
    int ulp_1 = dsu.findUPar(1); // Find the representative node of the set containing node 1
    int ulp_4 = dsu.findUPar(4); // Find the representative node of the set containing node 4
    if (ulp_1 == ulp_4) {
        cout << "Nodes 1 and 4 are in the same set" << endl;
    } else {
        cout << "Nodes 1 and 4 are in different sets" << endl;
    }

    return 0;
}

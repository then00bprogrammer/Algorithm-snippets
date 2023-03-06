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

    int find(int node) {
        return node==parent[node]?node:parent[node]=find(parent[node]);
    }

    void unite(int u, int v) {
        int ulp_u = find(u); 
        int ulp_v = find(v); 
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

class MST{
private:
    vector<pair<int, pair<int, int>>> adjToEdges(int V, vector<pair<int, int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
            edges.push_back({j.second, {i, j.first}});
            }
        }
        return edges;
    }
public:
    int Prim(int V,vector<pair<int,int>> adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> isVisited(V,false);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(isVisited[node])continue;
            isVisited[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(!isVisited[adjNode]){
                    pq.push({wt,adjNode});
                }
            }
        }
        return sum;
    }

    int Kruskal(int V,vector<pair<int,int>> adj[]){
        vector<pair<int, pair<int, int>>> edges=adjToEdges(V,adj);
        int n=edges.size();
        DisjointSet dsu(n);
        sort(edges.begin(),edges.end());
        int sum=0;
        for(auto edge:edges){
            int wt=edge.first;
            int src=edge.second.first;
            int dest=edge.second.second;
            if(dsu.find(src)!=dsu.find(dest)){
                dsu.unite(src,dest);
                sum+=wt;
            }
        }
        return sum;
    }
};

int main() {
    int n = 5; // Number of nodes
    DisjointSet dsu(n); // Create a disjoint set with n nodes

    // Merge nodes 1 and 2
    dsu.unite(1, 2);

    // Merge nodes 3 and 4
    dsu.unite(3, 4);

    // Merge nodes 2 and 3 (equivalent to merging nodes 1, 2, 3, and 4)
    dsu.unite(2, 3);

    // Check if nodes 1 and 4 are in the same set
    int ulp_1 = dsu.find(1); // Find the representative node of the set containing node 1
    int ulp_4 = dsu.find(4); // Find the representative node of the set containing node 4
    if (ulp_1 == ulp_4) {
        cout << "Nodes 1 and 4 are in the same set" << endl;
    } else {
        cout << "Nodes 1 and 4 are in different sets" << endl;
    }

    // create an MST object
    MST mst;

    // create a graph with 5 vertices and 6 edges
    int V = 5;
    vector<pair<int, int>> adj[V];
    adj[0].push_back({1, 3});
    adj[0].push_back({2, 2});
    adj[1].push_back({2, 4});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 3});
    adj[4].push_back({0, 7});

    // compute the MST using Prim's algorithm
    cout << "MST weight (Prim's algorithm): " << mst.Prim(V, adj) << endl;

    // compute the MST using Kruskal's algorithm
    cout << "MST weight (Kruskal's algorithm): " << mst.Kruskal(V,adj) << endl;

    return 0;
}

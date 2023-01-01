#include <bits/stdc++.h>
using namespace std;

class kosaraju{
private:
    void dfsTopo(int node,vector<int> &vis,vector<int> adj[],stack <int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
                dfsTopo(it,vis,adj,st);
        }
        st.push(node);
    }

    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }

public:
    int scc(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        stack <int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfsTopo(i,vis,adj,st);
        }

        vector <int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }

        int count=0;
        while (!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                ++count;
                dfs(node,vis,adjT);
            }

        }
        
        return count;
    }

};

int main(){
    // Initialize the number of vertices in the graph
    int V = 6;

    // Initialize the adjacency list of the graph
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(4);

    // Create an instance of the kosaraju class
    kosaraju K;

    // Find the number of SCCs in the graph
    int sccCount = K.scc(V, adj);

    // Print the result
    cout << "The number of SCCs in the graph is: " << sccCount << endl;
    // This would output: "The number of SCCs in the graph is: 2"

    return 0;
}


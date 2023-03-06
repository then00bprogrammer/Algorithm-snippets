#include <bits/stdc++.h>
using namespace std;

class kosaraju{
private:
    void dfs(int node,vector<int> &vis,vector<int> adj[],stack <int> *st=nullptr){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
                dfs(it,vis,adj,st);
        }
        if(st) st->push(node);
    }

public:
    int scc(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        stack <int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i,vis,adj,&st); //Pass stack so that the nodes get sorted in the order of visiting time
                //We do this so if we visit the scc 1 first then scc 2 and so on...
                //`https://youtu.be/R6uoSjZ2imo`
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

    // VISUALIZE -> `https://graphonline.ru/tmp/saved/bp/bpfuChsXKyXYKPTv.png`

    // Create an instance of the kosaraju class
    kosaraju K;

    // Find the number of SCCs in the graph
    int sccCount = K.scc(V, adj);

    // Print the result
    cout << "The number of SCCs in the graph is: " << sccCount << endl;
    // This would output: "The number of SCCs in the graph is: 2"
}
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int currentVertex,vector<int>&vis,vector<int>&recStack,vector<int>adj[])
    {
        vis[currentVertex] = 1;
        recStack[currentVertex] = 1;
        
        for(auto it : adj[currentVertex]){
            if(vis[it] == 0){
                if(dfs(it,vis,recStack,adj))
                    return true;
            }
            else if(recStack[it] == 1){
                return true;
            }
        }
        recStack[currentVertex] = 0;
        return false;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>recStack(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i] == 1) // already visited
                continue;
            if(dfs(i,vis,recStack,adj))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
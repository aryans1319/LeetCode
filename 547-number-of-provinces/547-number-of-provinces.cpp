class Solution {
public:
    void dfs(vector<vector<int>>& graph, int currentCity, int n,vector<bool>&vis){
        if(vis[currentCity]){
            return;
        }
        vis[currentCity] = true;
        for(int i=0 ;i<graph.size();i++){
            if(graph[currentCity][i] == 1 && !vis[i]){
                dfs(graph,i,n,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans = 0;
        
        vector<bool>vis(n,false);
        for(int currentCity = 0; currentCity < n; currentCity++){
            if(vis[currentCity] == false){
                dfs(graph, currentCity, n,vis);
                ans+=1;
            }
        }
        return ans;
    }
};
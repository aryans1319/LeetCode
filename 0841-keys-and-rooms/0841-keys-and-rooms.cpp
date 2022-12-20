class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>&vis,int node){
        vis[node]=1;
        for(auto neighbour:rooms[node]){
            if(!vis[neighbour])
                dfs(rooms,vis,neighbour);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);
        for(auto v: vis) if(!v) return false;
        return true;
    }
};
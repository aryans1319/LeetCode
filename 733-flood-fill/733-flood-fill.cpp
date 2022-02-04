class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>&grid, int sr, int sc, int newColor) {
        if(grid[sr][sc]==newColor) return grid;
        int m = grid.size();
        int n = grid[0].size();
        int color = grid[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row<0 || curr_row>=m || curr_col<0 || curr_col>=n || grid[curr_row][curr_col]!=color)
                continue;
            grid[curr_row][curr_col] = newColor;
            q.push({curr_row-1,curr_col});
             q.push({curr_row,curr_col+1});
             q.push({curr_row+1,curr_col});
             q.push({curr_row,curr_col-1});
        }
        return grid;
    }
};
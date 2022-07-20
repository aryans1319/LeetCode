class Solution {
public:
    void backtrack(vector<int>&nums, vector<int>&path, vector<bool>&visited,vector<vector<int>>&ans){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size();i++){
            if(!visited[i]){
                path.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums,path,visited,ans);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>ans;
        vector<bool> visited(nums.size(),false);
        backtrack(nums,path,visited,ans);
        return ans;
    }
};
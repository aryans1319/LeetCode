class Solution {
public:
    void backtrack(vector<int>&nums, vector<int>&path, vector<bool>&visited,vector<vector<int>>&ans){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size();i++){
            if(!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                backtrack(nums,path,visited,ans);
                path.pop_back();
                visited[i] = false;
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
class Solution {
public:
    int minJumps(vector<int>&nums,int currentIndex,int dp[10001]){
        
        if(currentIndex>=nums.size()-1){
            return 0;
        }
        
        if(dp[currentIndex]!=-1){
            return dp[currentIndex];
        }
        
        int currentJump = nums[currentIndex];
        int ans = 10001;
        for(int i=1 ;i <= currentJump ;i++){
            int tempAns = 1+ minJumps(nums,currentIndex+i,dp);
            ans=min(ans,tempAns);
        }
        dp[currentIndex]=ans;
        return dp[currentIndex];
    }
    
    int jump(vector<int>& nums) {
        int dp[10001];
        memset(dp,-1,sizeof(dp));
       return minJumps(nums,0,dp); 
    }
};
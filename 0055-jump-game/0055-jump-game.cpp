class Solution {
public:
  
bool isPossible(vector<int> &nums,int currentIndex,int dp[10001]){
        if(currentIndex>=nums.size()-1){
            return true;
        }
        
//         int currentKey = currentIndex;
        
//         if(mp.find(currentKey)!=mp.end()){
//             return mp[currentKey];
//         }
    if(dp[currentIndex]!=-1){
        return dp[currentIndex];
    }
        
        int currentJump = nums[currentIndex];
        bool ans=false;
        for(int i=1; i<=currentJump ;i++ ){
            bool tempAns = isPossible(nums,currentIndex+i,dp);
            ans = ans || tempAns;
            if(ans){
                return dp[currentIndex] = ans;
            }
        }
        return dp[currentIndex]=false;
    }
    bool canJump(vector<int>& nums) {
          int dp[10001];
        memset(dp,-1,sizeof(dp));
        return isPossible(nums,0,dp);
    }
};
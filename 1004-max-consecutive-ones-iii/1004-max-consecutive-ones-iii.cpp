class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int i=0,j=0;
        int zeroCount = 0;
        int ans = INT_MIN;
        
        while(j<nums.size()){
            if(nums[j]==0){
                zeroCount++;
            }
            
            while(zeroCount > k){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
       return ans;
    }
};
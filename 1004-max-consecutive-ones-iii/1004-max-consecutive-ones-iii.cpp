class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int ans = 0;
        int zeroCount = 0;
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zeroCount++;
            
            while(zeroCount>k){
                j++;
                if(nums[j]==0)
                    zeroCount--;
            }
            
            int len = i-j;
            if(len>ans)
                ans=len;
        }
        return ans;
    }
};
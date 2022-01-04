class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int currentSum = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            currentSum+=nums[j];
            
            if(currentSum<target){
                j++;
            }
            
            if(currentSum>=target){
                while(currentSum >= target ){
                    currentSum -= nums[i];
                    ans = min(ans, j-i+1);
                    i++;
                }
                 j++;
                
            }
        }
        return ans!= INT_MAX ? ans : 0;
    }
};
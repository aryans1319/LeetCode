class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        vector<int> leftProductArray(n);
        vector<int> rightProductArray(n);
        
        leftProductArray[0] = 1;
        rightProductArray[n-1] = 1;
        
        for(int i = 1 ;i<n;i++){
            leftProductArray[i] =  leftProductArray[i-1] * nums[i-1];
        }
        
        for(int j=n-2;j>=0;j--){
            rightProductArray[j] = rightProductArray[j+1] * nums[j+1];
        }
        
        for(int k = 0; k<n;k++){
            ans[k] = leftProductArray[k] * rightProductArray[k];
        }
        
        return ans;
    }
};
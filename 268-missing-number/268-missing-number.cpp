class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int tot=(n*(n+1))/2;
        for(auto x:nums){
            sum+=x;
        }
        return tot-sum;
    }
};
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    maxi=max(maxi, nums[j]-nums[i]);
                }
            }
        }
        return maxi;
    }
};
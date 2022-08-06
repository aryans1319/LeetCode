class Solution {
public:
    void generateAllSubarraysSum(vector<int>&nums, vector<int>&ans){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            for(int j = i; j < nums.size();j++){
                temp+=nums[j];
                ans.push_back(temp);
            }
        }
        return;
    }
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>allSubarrays;
        int mod = 1e9+7;
        generateAllSubarraysSum(nums,allSubarrays);
        // for(int i = 0 ;i <allSubarrays.size();i++){
        //     cout<<allSubarrays[i]<<" ";
        // }
        sort(allSubarrays.begin(), allSubarrays.end());
        long long sum = 0;
        for(int i = left-1; i<right;i++){
            sum += allSubarrays[i];
        }
        // cout<<"ok";
        return sum%mod;
    }
};
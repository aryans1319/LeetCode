class Solution {
public:
    int getMax(vector<int>&sums, int currentIndex,vector<int>&mp){
        if(currentIndex >= sums.size()){
            return 0;
        }
        
        if(mp[currentIndex]!=-1){
            return mp[currentIndex];
        }
        
        int earn = getMax(sums,currentIndex+2,mp) + sums[currentIndex];
        int del = getMax(sums, currentIndex + 1,mp);
        mp[currentIndex] = max(earn,del);
        return mp[currentIndex];
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>mp(10005,-1);
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> sum(maxi+1,0);
        for(int i=0; i<nums.size();i++){
            sum[nums[i]] += nums[i];
        }
        return getMax(sum,0,mp);
    }
};
class Solution {
public:
       int maxMoneyLooted(vector<int>&nums,int n, int currentIndex,unordered_map<int,int>&mp){
        
        //base condition
        
        if(currentIndex >= n){
            return 0;
        }
        //choices
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int lootenge = maxMoneyLooted(nums,n,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,n,currentIndex+1,mp);
        
        mp[currentKey] = max(lootenge,nhiLootenge);
        
        return   mp[currentKey];
        
    }
    
    int rob(vector<int>& nums) {
        // vector<int>temp1,temp2;
        int n = nums.size();
        if(n==1)return nums[0];
        unordered_map<int,int>mp,mp1;
        int first = maxMoneyLooted(nums,n-1,0,mp);
        int second = maxMoneyLooted(nums,n,1,mp1);
        // cout<<first<<" ";
        // cout<<second;
        return max(first,second);
        
    }
};
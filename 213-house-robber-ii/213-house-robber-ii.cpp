class Solution {
public:
       int maxMoneyLooted(vector<int>&nums, int currentIndex,unordered_map<int,int>&mp){
        
        //base condition
        
        if(currentIndex >= nums.size()){
            return 0;
        }
        //choices
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int lootenge = maxMoneyLooted(nums,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,currentIndex+1,mp);
        
        mp[currentKey] = max(lootenge,nhiLootenge);
        
        return   mp[currentKey];
        
    }
    
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n = nums.size();
        // if(n==1)return nums[0];
        for(int i = 0 ; i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
            
       
        }
        
        //      for(int i=0;i<temp1.size();i++){
        //     cout<<temp1[i]<<" ";
        // }
        //       for(int i=0;i<temp2.size();i++){
        //     cout<<temp2[i]<<" ";
        // }
        if(n==1) return nums[0];
        unordered_map<int,int>mp,mp1;
        int first = maxMoneyLooted(temp2,0,mp);
        int second = maxMoneyLooted(temp1,0,mp1);
        // cout<<first<<" ";
        // cout<<second;
        return max(first,second);
        
    }
};
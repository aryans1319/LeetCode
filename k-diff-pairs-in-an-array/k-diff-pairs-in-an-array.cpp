class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> memo;
        int count = 0;
         if(k<0){
            return 0;
        }
        for(auto i: nums){
            memo[i]++;
        }
         if(k == 0){
            for(auto c: memo){
                if(c.second>1)
                    count++;
            }
        }
        else{
            for(auto c: memo){
                if(memo.count(c.first-k)>0)
                    count++;
            }
        }
        return count;
    }
};
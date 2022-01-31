class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxpro=1;
        int minpro=1;
        int best=INT_MIN;
        
        if(nums.empty()) return 0;
        
        for(auto n:nums){
            if(n<0){
                swap(maxpro,minpro);
            }
            maxpro=max(maxpro*n,n);
            minpro=min(minpro*n,n);
            best=max(maxpro,best);
        }
        return best;
    }
};
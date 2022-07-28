class Solution {
public:
    int search(vector<int>& nums, int target) {
       if(binary_search(nums.begin(), nums.end(),target)!=1){
           return -1;
       } 
       return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};
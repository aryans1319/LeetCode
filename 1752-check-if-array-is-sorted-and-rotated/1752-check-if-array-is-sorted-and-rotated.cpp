class Solution {
public:
    bool check(vector<int>& nums) {
        /*
         if array is sorted rotated there is only 
         one breakpoint else 0 breakpoint
        */
        int breakPoint = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > nums[(i+1) % nums.size()]){
                breakPoint++;
            }
        }
        return breakPoint <= 1;
    }
};
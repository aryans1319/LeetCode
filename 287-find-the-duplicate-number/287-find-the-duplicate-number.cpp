class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int index = abs(nums[i]);
            if(nums[index] < 0){
                return index;
            }
            nums[index] = -nums[index];
        }
        return -1;
    }
};
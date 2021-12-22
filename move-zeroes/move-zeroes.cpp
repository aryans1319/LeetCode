class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snowBall = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0)
                snowBall++;
            else if(snowBall>0){
                int temp = nums[i];
                nums[i] = 0;
                nums[i-snowBall] = temp;
            }
        }
    }
};
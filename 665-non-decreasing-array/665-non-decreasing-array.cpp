class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool isModified = false;
        
        for(int i=1; i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                if(isModified) {
                    return false;
                }
                else{
                    isModified = true;
                    
                    if(i-2 >= 0 && nums[i] < nums[i-2]){
                        nums[i] = nums[i-1];
                    }
                }
            }
        }
        return true;
    }
};
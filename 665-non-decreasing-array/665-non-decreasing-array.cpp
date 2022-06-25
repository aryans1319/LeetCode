class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool isModified = false;
         // Initially we are allowed to make one change
        for(int i=1; i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                if(isModified) {
                       //we made one change and still there is problem so we return false
                    return false;
                }
                else{
                    isModified = true;
                       /*
                      We are at i and check whether it is greater than its previous to previous neighbour(= i - 2)
                      (why? cause if it less than that than we have no choice but to increment this(= i) value. 
                      But if it is greater we can decrease i - 1'th element cause it is always better to decrease a value than increasing. 
                      If i'th element is smaller than i - 2'th than we have to increment i, and we do it just till the value of i - 1'th, cause further                             increasing might clash with later values.
                      One thing i got stuck was why are we than not decreasing the value of i - 1'th element then,
                      cause we don't need to cause if there is another clash we just return false.
                    */
                    if(i-2 >= 0 && nums[i] < nums[i-2]){
                        nums[i] = nums[i-1];
                    }
                }
            }
        }
        return true;
    }
};
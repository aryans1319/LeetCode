class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int shift = 0;
        for(int i=0;i<n-1;i++){
            if((i+shift)%2 == 0){
                if(nums[i] == nums[i+1]){
                    shift++;
                }
            }
        }
        if((n - shift) %2 ==1){
            shift++;
        }
        return shift;
        // int shift = 0;
        //     for (int i = 0; i < nums.size() - 1; i++)
        //     {
        //         if ((i + shift) % 2 == 0)
        //         {
        //             if (nums[i] == nums[i + 1])
        //             {
        //                 shift++;
        //             }
        //         }
        //     }
        //     if ((nums.size() - shift) % 2 == 1)
        //     {
        //         shift++;
        //     }
        //     return shift;
    }
};
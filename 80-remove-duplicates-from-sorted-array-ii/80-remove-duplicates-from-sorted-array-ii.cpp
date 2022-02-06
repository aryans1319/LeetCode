class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n=nums.size();
        if(n<3)
            return n;
        int s=2,f=2;
        while(f<n){
            if(nums[f]!=nums[s-2])
                nums[s++]=nums[f];
            f++;
            
        }
        return s;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int len = nums.size();
        
        // Corner Case: 
        
        if(nums[start] <= nums[end]){
            return nums[start];
        }
        
        while(start <= end){
            int mid = start + (end-start)/2;
            int next = ((mid + len - 1)%len);
            
            if(nums[mid] <= nums[next]){
                return nums[mid];
            }
            else if(nums[mid] >= nums[0]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return 0;
    }
};
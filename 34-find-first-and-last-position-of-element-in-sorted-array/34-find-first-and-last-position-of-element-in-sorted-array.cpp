class Solution {
public:
    int firstOccurence(vector<int>&nums, int target){
      int start = 0;
      int end = nums.size()-1;
      int res = -1;
      while(start <= end){
       int mid = start + (end - start)/2;        
        if(nums[mid] == target){
          res = mid;
          end = mid-1;
        }
        else if(nums[mid] < target){
          start = mid+1;
        }
        else{
          end = mid-1;
        }
      }
     return res;   
}
    int lastOccurence(vector<int>&nums, int target){
      int start = 0;
      int end = nums.size()-1;
      int res = -1;
      while(start <= end){
       int mid = start + (end - start)/2;        
        if(nums[mid] == target){
          res = mid;
          start = mid+1;
        }
        else if(nums[mid] < target){
          start = mid+1;
        }
        else{
          end = mid-1;
        }
      }
     return res;   
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int a = firstOccurence(nums,target);
        int b = lastOccurence(nums,target);
        ans.push_back(a);ans.push_back(b);
        return ans;
    }
};
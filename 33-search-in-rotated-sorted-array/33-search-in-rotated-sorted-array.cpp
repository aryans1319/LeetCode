class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l,int r) {
        int start = l;
        int end = r;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int len = nums.size(); 
        
        if(nums[start] <= nums[end]){
            return nums[start];
        }
        
        while(start <= end){
            int mid = start + (end-start)/2;
            int next = ((mid + len - 1)%len);
            
            if(nums[mid] <= nums[next]){
                return mid;
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
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIndex = findMin(nums);
        cout<<minIndex<<" ";
        int a = binarySearch(nums,target,0,minIndex-1);
        int b = binarySearch(nums,target,minIndex,n-1);
        
        if(a == -1)
            return b;
        else
            return a; 
    }
};
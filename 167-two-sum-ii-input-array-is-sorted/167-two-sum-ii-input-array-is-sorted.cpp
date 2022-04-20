class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        int start = 0;
        int end = n-1;
        
        vector<int>ans({});
        
        /* 
        
           The idea is very simple since the array is sorted
           we can use the two pointer technique in order to 
           solve this problem
           
           Keep a start pointer at index = 0 and an end pointer
           at n-1
           
           There can be 3 possible cases:  
           
           Case 1 : nums[start] + nums[end] == target 
           
           --->     Then we can simply return the indexes + 1 
                    and we got out target indexes
           
           Case 2 : nums[start] + nums[end] > target 
           
           --->     if the value is greater than the target
                    we can say that in order to get our desired 
                    value we need to reduce the sum, and as we know
                    the array is sorted in increasing order
                    we can just reduce the value by decrementing
                    the end pointer do that end--
                    
           Case 3 : nums[start] + nums[end] < target
           
           --->     Just reverse of case 2, if value is less than target
                    we can increment the starting pointer 
         
         */           
        
        while(start <= end){
            int sum = nums[start] + nums[end];
            
            if(sum == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
            
            if(sum > target){
                end--;
            }  
            else if(sum < target){
                start++;
            }
        }
        return ans;
    }
};
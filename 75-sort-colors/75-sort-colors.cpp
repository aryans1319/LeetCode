class Solution {
public:
    void sortColors(vector<int>& nums) {
         /*
         
         We can use a Dutch National Flag Algorithm there to 
         solve this problem in linear time O(n) - Best optimal Solution
         
         Counting Sort can be used but it takes O(N) + O(N) in worst case
         
         Intuition behind: 
         In this approach, we will be using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary              goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and          hence the array will be sorted. 

            Approach: 

            Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index
            int low = arr[0]

            int mid = arr[0]

            int high = arr[n – 1]

            Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

            arr[mid] == 0:
            swap(arr[low], arr[mid])
            low++, mid++

            arr[mid] == 1:
            mid++

            arr[mid] == 2:
            swap(arr[mid], arr[high])
            high–;
            The array formed after these steps will be a sorted array.
            
            */
        int n = nums.size();
        
        int low = 0;
        int mid = 0;
        
        int high = nums.size()-1;
        
        while(mid <= high){
            
            switch(nums[mid]){
                 
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
                    
            }
            
        }
        
         
    }
};
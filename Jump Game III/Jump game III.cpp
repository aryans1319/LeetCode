/*************************************

1306. Jump Game III

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

***************************************/

/**********************CODE***************************/


class Solution {
public:
    bool solve(vector<int>& arr , int start , vector<bool>& visited){
        if(start < 0 || start >= arr.size())
            return false;
        if(visited[start])
            return false;
        if(arr[start] == 0)
            return true;
        visited[start] = true;
        return solve(arr , start-arr[start] , visited) || solve(arr,start+arr[start], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n , false);
        return solve(arr , start , visited);
    }    
};
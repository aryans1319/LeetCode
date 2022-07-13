class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //optimal Approach
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i = 0;
        int j = m-1;
        
        while(i < n && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int start = 0;
//         int end = m*n  - 1;
        
//         while(start <= end){
//             int mid = start + (end-start)/2;
            
//             int currentRow = mid/n;
//             int currentCol = mid%n;
            
//             if(matrix[currentRow][currentCol] == target){
//                 return true;
//             }
            
//             if(matrix[currentRow][currentCol] < target){
//                 start = mid + 1;
//             }
//             else{
//                 end = mid - 1;
//             }
//         }
//         return false;
    }
};
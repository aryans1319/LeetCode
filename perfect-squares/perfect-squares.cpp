class Solution {
public:
   int numSquares(int n) { 
        int dp[10000 + 1][100 + 1]; 
        memset(dp, -1, sizeof(dp)); 
         
        int perfectSquareCount =  sqrt(n); 
        vector<int> vec; 
        PerfectSquares(vec, perfectSquareCount); 
         
        return Solve(vec,0, n, dp); 
    } 
     
    void PerfectSquares(vector<int> &vec, int n) { 
        while(n) { 
            vec.push_back(n*n); 
            n--; 
        } 
    } 
     
    int Solve(vector<int> &vec,int currentIndex, int target, int dp[][100+1]) { 
       if(target == 0) {
            return 0;
        }
        if(vec[currentIndex] == 1) { 
            return target; 
        } 
         
        if(dp[target][currentIndex] != -1) { 
            return dp[target][currentIndex]; 
        } 
         
        int considerAdding = 10000; 
        if(vec[currentIndex] <= target) { 
            considerAdding = 1 + Solve(vec, currentIndex, target-vec[currentIndex], dp); 
        } 
        int notConsiderAdding = 0 + Solve(vec, currentIndex+1, target, dp); 
         
        dp[target][currentIndex] = min(considerAdding, notConsiderAdding); 
        return dp[target][currentIndex]; 
    } 
};
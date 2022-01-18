class Solution {
public:
     int dp[10000 + 1][100 + 1];
   int numSquares(int n) { 
        
        memset(dp, -1, sizeof(dp)); 
         // unordered_map<string,int>mp;
        int perfectSquareCount =  sqrt(n); 
        vector<int> vec; 
        PerfectSquares(vec, perfectSquareCount); 
         
        return Solve(vec,0, n); 
    } 
     
    void PerfectSquares(vector<int> &vec, int n) { 
        while(n) { 
            vec.push_back(n*n); 
            n--; 
        } 
    } 
     
    int Solve(vector<int> &vec,int currentIndex, int target) { 
       if(target == 0) {
            return 0;
        }
        if(vec[currentIndex]==1) { 
            return target; 
        } 
         
        // string currentKey = to_string(currentIndex)+ "_"+ to_string(target);
        if(dp[target][currentIndex] != -1) { 
            return dp[target][currentIndex]; 
        } 
        
        // if(mp.find(currentKey)!=mp.end()){
        //     return mp[currentKey];
        // }
         
        int considerAdding = 10000; 
        if(vec[currentIndex] <= target) { 
            considerAdding = 1 + Solve(vec, currentIndex, target-vec[currentIndex]); 
        } 
        int notConsiderAdding = 0 + Solve(vec, currentIndex+1, target); 
        dp[target][currentIndex] = min(considerAdding, notConsiderAdding); 
         return  dp[target][currentIndex]  ;
        
    } 
};
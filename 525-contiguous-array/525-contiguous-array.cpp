class Solution {
public:
    int findMaxLength(vector<int>& A) {
        int prefixSum = 0;
        int ans = 0;
        
        unordered_map<int,int>mp;
        // mp[0]=-1;
        for(int i=0;i<A.size();i++){
//             prefixSum+=A[i];
            
            if(A[i] == 0){
                prefixSum+=-1;
            }
            else {
                prefixSum+=A[i];
            }
            if(prefixSum == 0){
                ans = i+1;
            }
            else{
            if(mp.find(prefixSum)!=mp.end()){
                int lastOccIndexLen = i - mp[prefixSum];
                ans = max(ans,lastOccIndexLen);
            }
            else{
                mp[prefixSum] = i;
            }
            }
        }
        return ans;
    }
};
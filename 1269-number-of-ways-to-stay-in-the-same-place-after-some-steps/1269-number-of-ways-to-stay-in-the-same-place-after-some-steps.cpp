
class Solution {
public:
   int mod = 1e9+7;
    long long totalWays(int steps,int arrLen,int cI,unordered_map<string,int>&mp){
        if(steps == 0 && cI == 0){
            return 1;
        }
        if(cI >= arrLen || cI<0 || steps==0){
            return 0;
        }
        
        string currentKey = to_string(steps) + "_" + to_string(cI);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        long long left = totalWays(steps-1,arrLen,cI-1,mp);
        long long right = totalWays(steps-1,arrLen,cI+1,mp);
        long long stay = totalWays(steps-1,arrLen,cI,mp);
        mp[currentKey] = (left+right+stay)%mod;
        return mp[currentKey];
    }
    int numWays(int steps, int arrLen) {
        unordered_map<string,int>mp;
        return totalWays(steps,arrLen,0,mp)%mod;
    }
};
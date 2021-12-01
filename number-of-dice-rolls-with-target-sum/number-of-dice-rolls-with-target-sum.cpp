class Solution {
public:
    int totalWays(int d,int f,int target,unordered_map<string,int>&mp){
        if(d==0 and target!=0){
            return 0;
        }
        
        if(d==0 and target==0){
            return 1;
        }
        
        string currentKey = to_string(d) + "_" + to_string(target);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        int ans=0;
        for(int current=1;current<f+1;current++){
            int tempAns = totalWays(d-1,f,target-current,mp);
            ans= (ans%1000000007 + tempAns%1000000007)%1000000007;
        }
        mp[currentKey] = ans;
        return mp[currentKey];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        unordered_map<string,int>mp;
        return totalWays(d,f,target,mp)%1000000007;
    }
};
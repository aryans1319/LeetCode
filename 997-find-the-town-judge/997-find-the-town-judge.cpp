class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n+1,0);
        vector<int>outDegree(n+1,0);
        
        for(auto currentTrust: trust){
            int a = currentTrust[0];
            int b = currentTrust[1];
            
            inDegree[b]+=1;
            outDegree[a]+=1;
        }
        
        for(int currentPeople = 1; currentPeople <= n; currentPeople++){
            if(inDegree[currentPeople] == n-1 && outDegree[currentPeople] == 0){
                return currentPeople;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool maxStones(vector<int> &piles,bool alice , int start , int end, unordered_map<string,int> &mp){
        if(start > end){
            return 0;                
        }
        
        string currentKey = to_string(start) + " " + to_string(end);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        if(alice){
            int pickFromStart = piles[start] + maxStones(piles,alice,start+1,end,mp);
            int pickFromEnd = piles[end] + maxStones(piles,alice,start,end-1,mp);
            mp[currentKey] = max(pickFromStart,pickFromEnd);
            return mp[currentKey];
        }
        else{
            int bobStart = -piles[start] + maxStones(piles,alice,start+1,end,mp);
            int bobEnd = -piles[end] + maxStones(piles,alice , start,end-1,mp);
            mp[currentKey] = min(bobStart,bobEnd);
            return   mp[currentKey];
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        unordered_map<string,int>mp;
        int n = piles.size();
        return maxStones(piles , true , 0,n-1,mp)>0;
    }
};
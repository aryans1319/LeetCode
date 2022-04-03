class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>candleIndex;
        for(int i=0;i<s.size();i++){
            if(s[i] == '|'){
                candleIndex.push_back(i);
            }
        }
        vector<int>ans;
        for(auto i : queries){
            int first = lower_bound(candleIndex.begin(),candleIndex.end(), i[0]) - candleIndex.begin();
            int last = upper_bound(candleIndex.begin() , candleIndex.end() , i[1]) - candleIndex.begin()-1;
            
            if(last<=first){
                ans.push_back(0);
                continue;
            }
            
            
          int tempAns = candleIndex[last] - candleIndex[first] - (last - first);
            ans.push_back(tempAns);
    }
        return ans;
    }
};
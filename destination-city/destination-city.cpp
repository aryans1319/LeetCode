class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> memo;
        for(auto &e: paths){
            memo.insert(e[0]);
        }
        for(auto &e: paths){
            if(memo.find(e[1])==memo.end())
                return e[1];
        }
        return "";
    }
};
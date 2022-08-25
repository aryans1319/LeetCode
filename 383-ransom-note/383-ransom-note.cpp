class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(auto i : magazine){
            mp[i]++;
        }
        // bool flag = true;
        for(auto i : ransomNote){
            if(--mp[i] < 0) return false;
        }
        return true;
    }
};
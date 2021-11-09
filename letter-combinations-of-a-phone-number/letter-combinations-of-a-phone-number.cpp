class Solution {
public:
    vector<string>help(string &s,int i,map<int,string>mp){
        if(i==s.size())return {""};
        vector<string> temp=help(s,i+1,mp);
        vector<string>ans;
        
        for(auto a: mp[s[i]-'0']){
            for(auto x:temp){
                ans.push_back(a+x);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        if(digits.size()==0)return {};
        mp[2]="abc";
         mp[3]="def";
         mp[4]="ghi";
         mp[5]="jkl";
         mp[6]="mno";
         mp[7]="pqrs";
         mp[8]="tuv";
        mp[9]="wxyz";
        return help(digits,0,mp);
    }
};
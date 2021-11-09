class Solution {
public:
    vector<string>ans;
    void solve(string s,int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            solve(s+'(',open-1,close);
        }
        if(open<close){
            solve(s+')',open,close-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve("",n,n);
        return ans;
    }
};
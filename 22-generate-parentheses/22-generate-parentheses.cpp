class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generateCombinations(0,0,"",n,ans);
        return ans;
    }
    
    void generateCombinations(int openCount, int closeCount, string expression, int n, vector<string>&ans)
    {
        if(openCount == closeCount && openCount == n){
            ans.push_back(expression);
            return;
        }
        if(openCount < n){
             generateCombinations(openCount + 1, closeCount, expression + "(",n ,ans);
        }
        if(openCount > closeCount){
             generateCombinations(openCount, closeCount+1, expression + ")", n, ans);
        }
        return;
    }
    
};
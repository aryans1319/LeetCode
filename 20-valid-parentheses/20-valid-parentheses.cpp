class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>symbols={{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};
        stack<char>st;
        for(char brackets:s){
            if(symbols[brackets]<0){
                st.push(brackets);
            }
            else{
                if(st.empty())
                    return false;
                char top=st.top();
                st.pop();
                if(symbols[top]+symbols[brackets]!=0){
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
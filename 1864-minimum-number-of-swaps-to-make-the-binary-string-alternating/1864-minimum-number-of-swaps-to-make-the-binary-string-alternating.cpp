class Solution {
public:
    int solve (string s, char ch){
        int swap = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ch && i%2!=0 ) swap++;
        }
        return swap;
    }
    int minSwaps(string s) {
        int one = 0;
        int zero = 0;
        
        for(auto i : s){
            if(i=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        if(abs(one-zero) > 1)
            return -1;
        
        if(zero > one) return solve(s,'0');
        if(one > zero) return solve(s,'1');
        
        return min(solve(s,'0'), solve(s,'1'));
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
    int i=0,j=0;
    int mx = -1;
    int ans = 0;    
    unordered_map<char,int> memo;
    while(j<s.length()){
        memo[s[j]]++;
        
        ans = max(ans, memo[s[j]]);
        if((j-i+1) - ans > k){
            memo[s[i]]--;
            i++;
        }
        mx = max(mx,j-i+1);
        j++;
    }
    return mx;
    }
};
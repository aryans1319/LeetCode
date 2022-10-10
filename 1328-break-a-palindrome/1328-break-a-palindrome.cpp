class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        string ans = "";
        if(n == 1){
            return ans;
        }
        else{
            for(int i = 0; i < n / 2; i++){
                if(palindrome[i] != 'a'){
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
            palindrome[n-1] = 'b';
        }
        return palindrome;
    }
};
class Solution {
public:
    /*
        Criteria for being: 
        Bull : Character is present in both secret and guess
               and position is same
        Cows : Character is present in both but positions are
               different
        Compare both secret and guys and return output in the form 
        of xA yB where x = number of bulls
                       y = number of cows
    */
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> s(10, 0), g(10,0);
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) {
                bulls++;
            }
            else {
                // converting string to int and counting freq
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            cows += min(s[i], g[i]);
        }
        string ans = "";
        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
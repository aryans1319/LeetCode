class Solution {
public:
    string greatestLetter(string s) {
        vector<int> smallerChar(26,0);
        vector<int> capitalChar(26,0);
        
        string ans ;
        
        for(auto i : s){
            if(i >= 'a' && i <= 'z'){
                smallerChar[i - 'a']++;
            }
            else{
                capitalChar[i - 'A']++;
            }
        }
        
        for(int i=25; i >= 0; i--){
            if(smallerChar[i] && capitalChar[i]){
                char greatestCapitalLetter = i + 'A';
                ans.push_back(greatestCapitalLetter);
                return ans;
            }
        }
        
        return ans;
    }
};
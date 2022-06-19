class Solution {
public:
    string greatestLetter(string s) {
        /* 
           Make two Frequency array for both smaller case alphabets and
           capital case respectively 
        */   
        vector<int> smallerChar(26,0);
        vector<int> capitalChar(26,0);
        
        string ans;
        
        for(auto i : s){
            if(i >= 'a' && i <= 'z'){
                smallerChar[i - 'a']++;
            }
            else{
                capitalChar[i - 'A']++;
            }
        }
        
        /* 
           if Both upper and lower case of a letter is present store the capital letter in
           string ans as we are traversing from back so it would be the greater char only!
        */ 
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
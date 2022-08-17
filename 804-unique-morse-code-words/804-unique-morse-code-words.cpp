class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>st;
        vector<string>code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word: words){
            string temp = ""; 
            for(auto ch : word){
                temp += code[ch-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};
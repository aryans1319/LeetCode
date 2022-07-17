class Solution {
public:
    private:
        string KEY[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size() == 0) return ans;
        generateCombinations(digits, 0, "", ans);
        return ans;
    }
    
    void generateCombinations(string digits, int currentIndex, string currentString, vector<string>&ans){
        
        if(currentIndex >= digits.size()){
            ans.push_back(currentString);
            return;
        }
        
        char currentChar = digits[currentIndex];
        string letters = KEY[currentChar - '0'];
        
        for(int i = 0; i< letters.size();i++){
            generateCombinations(digits, currentIndex + 1, currentString + letters[i], ans);
        }
        return; 
    }
    
};
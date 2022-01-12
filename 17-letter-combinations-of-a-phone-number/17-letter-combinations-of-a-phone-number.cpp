class Solution {
    private:
    void allPossibleMappings(string digits,string currentAns,int currentIndex,vector<string>&ans,string mapping[]){
        if(currentIndex >= digits.length()){
            ans.push_back(currentAns);
            return;
        }
        
        int number = digits[currentIndex] -'0';
        string value = mapping[number];
        
        for(int i=0;i<value.length();i++){
            currentAns.push_back(value[i]);
            allPossibleMappings(digits,currentAns,currentIndex+1,ans,mapping);
            currentAns.pop_back();
        }
    }   
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string currentAns;
        if(digits.length()==0){
            return ans;
        }
        int currentIndex = 0;
        string keypad[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        allPossibleMappings(digits,currentAns,currentIndex,ans,keypad);
        return ans;
    }
};
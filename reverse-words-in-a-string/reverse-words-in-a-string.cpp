class Solution {
public:
    string reverseWords(string s) {
     vector<string> vec;
        stringstream str(s);
        string word;
        while (str >> word) // store separated words in vector
            vec.push_back(word);
        
        reverse(vec.begin(), vec.end()); // reverse vector
        
        string res;
        for (const auto &it : vec) // concatenate strings
            res+=" "+it;
        res.erase(0,1); // first place is always a space - extra
        
        return res;
    }
};
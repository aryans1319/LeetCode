class Solution {
public:
    bool wordPattern(string pattern, string s) {
         unordered_map<char,string> map;
        unordered_map<string,bool> used;
        vector<string> words;
        stringstream ss(s);
        while(ss >> s){
            words.push_back(s);
        }
        if(words.size()!=pattern.size()){
            return false;
        }
       else{

        for(int i = 0 ;i < pattern.size();i++){
            char ch = pattern[i];
            
            if(map.find(ch)==map.end()){
                if(used.find(words[i])!=used.end()){
                    return false;
                }
                 else{
                used[words[i]] =true;
                map[ch] = words[i];
            }
            }
            
            else{
               string mappedWith = map[ch];
                if(mappedWith!=words[i])
                    return false;
            }
        }}
    
       
        return true;
    }
};
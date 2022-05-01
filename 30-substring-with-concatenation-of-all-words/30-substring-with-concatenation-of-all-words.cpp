class Solution {
public:
    /* 
    
    Question states that we are given an array
    of words = ["foo","bar"] concatenate the words given in 
    the array of words 
    1) "foobar"
    2) "barfoo"
    
    Now in the given string s, find substrings "foobar" & "barfoo"
    and store the first occuring index of both subtring in a 
    vector and return it
    
     s = "b a r f o o t h e f  o  o  b  a  r   m  a  n"
          0 1 2 3 4 5 6 7 8 9 10  11 12 13 14  15 16 17 
          
          barfoo    foobar
                        
          0         9
          
          we got one substring at index 0 and another at 
          0  [0, 9]
    
    Approach : 
     
    Observe what would be the length of the substring to find in s
    it would be 6 in this case ("foobar" "barfoo" length = 6 i.e we can say length of
    each word * no of words (3*2 =6 in this case))
    
    No need to concatenate anything / find permutations to determine the presence
    of it in the main string
    
    We just need to check if the words of strings is present in the main string or
    not if yes then we got what we wanted 
    if not then present there can be two possibilities
    1) word absent in that case break
    2) word present but count is > for eg : "foo", "bar"
                                            "foofoobar" "foo" -> 2 times
                                            in this case to we break out of loop
                                            
    
    */
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int singleWordLen = words[0].size();
        int totalNoOfWords = words.size();
        vector<int>ans;
        
        if(singleWordLen * totalNoOfWords > s.size()){
            return ans;
        }
        /* Storing each word and its occurence in map */
        unordered_map<string,int> mp;
        for(auto word : words ){
            mp[word]++;
        }
        
        for(int i = 0; i <= s.size() - (singleWordLen * totalNoOfWords) ; i++){
            unordered_map<string,int> occuredWord;
            /* Checking for each word in main string */
            
            for(int j=i; j < i + (singleWordLen * totalNoOfWords); j+=singleWordLen) {
                
                string currentString = s.substr(j,singleWordLen); // substring of length = each word len
                
                if(mp.find(currentString) == mp.end()){
                    break;
                }
                /* If any word occur more than once "foofoobar" foo -> 2 times increment count*/
                occuredWord[currentString]++; 
                
                if(occuredWord[currentString] > mp[currentString]){
                    break;
                }
            }
            /*if both map are equal that means the word concatenated which 
            we wanted is present in main string so push its index */
                if(occuredWord == mp){
                    ans.push_back(i);
                }
                
        }
        
        return ans;
    }
};
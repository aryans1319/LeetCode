class Solution {
public:
    int maxPower(string s) {
       vector<int> v;
        int c=1;
        if(s.size()==1){
            return 1;
        }
        else{
       for(int i=1;i<s.size();i++){
           if(s[i]==s[i-1]){
               c++;
           }
           else{
               c=1;
           }
            v.push_back(c);
       } 
        }
        return *max_element(v.begin(),v.end());
    }
};
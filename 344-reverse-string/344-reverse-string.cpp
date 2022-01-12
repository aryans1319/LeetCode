class Solution {
public:
    void reverse(int i, vector<char> &s){
        int n=s.size();
        if(i>=n/2)return;
        else{
            swap(s[i],s[n-i-1]);
            reverse(i+1,s);
        }
    }
    
    
    void reverseString(vector<char>& s) {
        reverse(0,s);
    }
};
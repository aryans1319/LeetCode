class Solution {
public:
    int minFlips(string target) {
        int c = 0;
        int n = target.size();
        char ch = '0';
        for(int i=0; i < n; i++){
           if(target[i]!=ch){
               c++;
               ch = target[i];
           }
        }
        return c;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string say = countAndSay(n-1);
        int len = say.size();
        string newSay = "";
        for(int i=0; i<len; ){
            int j = i+1;
            while(j<len && say[i] == say[j]){
                j++;
            }
            newSay += to_string(j-i) + say[i];
            i = j;
        }
        return newSay;
    }
};
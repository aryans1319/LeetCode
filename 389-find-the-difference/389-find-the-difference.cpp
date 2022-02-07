class Solution {
public:
    char findTheDifference(string s, string t) {
       int sum = 0,sum1=0;
        for(auto a : s){
            sum+=a;
        }
        for(auto c : t){
            sum1+=c;
        }
        return sum1-sum;
    }
};
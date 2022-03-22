class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k-=n;
        int currentIndexFromBack = n-1;
        
        while(k > 0){
            int tempAns = min(k,25);
            ans[currentIndexFromBack]+=tempAns;
            k-=tempAns;
            currentIndexFromBack--;
        }
        return ans;
    }
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         int res = 0, cur = 0;
        for (int a: values) {
            res = max(res, cur + a);
            cur = max(cur, a) - 1;
        }
        return res; 
    }
};
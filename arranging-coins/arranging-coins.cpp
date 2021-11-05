class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        long total = 1;
        while (total <= n) {
            total += ++k;
        }
        return k-1;
    }
};
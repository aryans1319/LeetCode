class Solution {
public:
    bool detectCapitalUse(string word) {
         const int n = word.size();
        bool isFirstUpper = isupper(word[0]);
        int upper = 0, lower = 0;

        for (int i = 0; i < n; ++i) {
            if (isupper(word[i])) {
                ++upper;
            } else {
                ++lower;
            }
        }
        return lower == n || upper == n || (isFirstUpper && lower == n - 1);
    }
};
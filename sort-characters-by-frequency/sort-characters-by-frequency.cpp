class Solution {
public:
    string frequencySort(string s) {
           int cnt[128] = {};
        for (char c : s) cnt[c] += 1;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        return s;
    }
};
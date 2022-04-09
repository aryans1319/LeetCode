class Solution {
public:
    int getMinSwaps(string num, int k) {
        string perm = num; 
        while (k--) 
            next_permutation(perm.begin(), perm.end()); 
        
        int ans = 0; 
        for (int i = 0; i < num.size(); ++i) {
            int ii = i; 
            while (num[i] != perm[i]) {
                ++ans; 
                swap(perm[i], perm[++ii]); 
            }
        }
        return ans; 
    }
};
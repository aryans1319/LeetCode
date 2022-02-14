class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long n = beans.size();
        sort(beans.begin(),beans.end());
        // int mini = *min_element(beans.begin(),beans.end());
         long sum = accumulate(beans.begin(),beans.end(),0L);
         long ans = LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            ans = min(ans,sum-(n-i)*beans[i]);
        }
        return ans;
    }
};
class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int n = salary.size();
        for(auto i : salary){
            sum+=i;
        }
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
        sum = sum -(maxi+mini);
        int x = n-2;
        double ans = (double)(sum/x);
        return ans;
    }
};
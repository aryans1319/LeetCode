class Solution {
public:
    long long int robb(vector<long long int>& nums) {
        long long int n = nums.size();
        long long int prev1 = nums[0];
       long long int prev2 = 0;
        for(long long int i=1;i<n;i++){
            long long int pick = nums[i];
            if(i>1){
                pick+=prev2;
            }
            long long int notPick = 0 + prev1;
            long long int curi = max(pick,notPick);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
    int rob(vector<int>& valueInHouse) {
       vector<long long int>first,second;
    long long int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    
    for(long long int i=0;i<n;i++){
        if(i!=0) first.push_back(valueInHouse[i]);
        if(i!=n-1) second.push_back(valueInHouse[i]);
    }
     long long int ans1 = robb(first);
     long long int ans2 = robb(second);
    return max(ans1,ans2);
    }

};
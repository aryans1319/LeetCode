typedef long long ll;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size(); 
        vector<ll> left(n);
        vector<ll> right(n); 
         ll maxi=1e18; 
        ll ans=0;  
          right[n-1]=0; 
        for(int i=n-2;i>=0;i--){ 
            right[i]=(right[i+1]+nums[i+1]); 
        } 
        for(int i=n-2;i>=0;i--){ 
            right[i]=right[i]/(n-i-1); 
        }
        left[0]=nums[0]; 
        for(int i=1;i<n;i++){ 
            left[i]=(left[i-1]+nums[i]); 
        } 
        for(int i=1;i<n;i++){ 
            left[i]=left[i]/(i+1); 
        } 
        for(int i=n-1;i>=0;i--){ 
            int xy=abs(left[i]-right[i]); 
            if(xy<=maxi){ 
                maxi=xy; 
                ans=i; 
            } 
        } 
        return ans; 
        // return mini;         
    }
};

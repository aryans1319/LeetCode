// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n);
	    dp[0] = arr[0];
	    int neg = 0;
	    for(int i=1;i<n;i++){
	        int pick = arr[i];
	        if(i>1)
	        {
	            pick+=dp[i-2];
	        }
	        int notPick = 0 + dp[i-1];
	        dp[i] = max(pick,notPick);
	    }
	    return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
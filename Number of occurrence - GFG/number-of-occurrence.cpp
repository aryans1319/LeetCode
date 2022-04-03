// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		 int firstOccurence(int nums[],int n,int target){
        int start = 0;
        int end = n-1;
        
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                res = mid;
                end = mid-1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;

    }
    int lastOccurence(int nums[],int n,int target){
        int start = 0;
        int end = n-1;
        
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                res = mid;
                start = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
	int count(int arr[], int n, int x) {
	    int a = firstOccurence(arr,n,x);
        int b = lastOccurence(arr,n,x);
        
        if(a==-1 && b==-1){
            return 0;
        }
        return b-a+1;
        
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
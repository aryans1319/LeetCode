// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        // sort(arr,arr+n);
        unordered_map<int,int>mp;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end())
            {
    
                maxi = max(maxi,i-mp[arr[i]]);
            }
            else{
                mp[arr[i]] = i;
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
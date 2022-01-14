// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int maxProfit(int W, int wt[],int currentIndex , int val[],int n,unordered_map<string,int>&mp){
        if(currentIndex >= n){
            return 0;
        }
        
        int consider = INT_MIN;
        
        string currentKey = to_string(currentIndex) + "_" + to_string(W);
        
        if(mp.find(currentKey)!= mp.end()){
            return mp[currentKey];
        }
        
        if(wt[currentIndex] <= W){
            consider = maxProfit(W-wt[currentIndex], wt,currentIndex+1,val,n,mp) + val[currentIndex];
        }
        int notConsider = maxProfit(W,wt,currentIndex+1,val,n,mp);
        
        mp[currentKey] = max(consider,notConsider);
        
        return  mp[currentKey];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<string,int>mp;    
        return maxProfit(W,wt,0,val,n,mp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
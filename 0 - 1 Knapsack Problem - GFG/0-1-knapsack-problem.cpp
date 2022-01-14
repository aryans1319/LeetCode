// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    
    int maxProfit(int W,int wt[],int val[],int n,int currentIndex,unordered_map<string,int>&mp){
        
        if(currentIndex >= n){ // or if W==0 return 0
            return 0;
        } 
        
        string currentKey = to_string(currentIndex) + "_" + to_string(W);
        
        if(mp.find(currentKey)!=mp.end()){
           return mp[currentKey];
        }
        
        int pick = 0;
        if(wt[currentIndex] <= W){
            pick = val[currentIndex] + maxProfit(W-wt[currentIndex], wt,val,n,currentIndex+1,mp);
        }
        
        int notPick = maxProfit(W,wt,val,n,currentIndex+1,mp);
        
        mp[currentKey] = max(pick,notPick);
        
        return  mp[currentKey];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<string,int>mp;
       return maxProfit(W,wt,val,n,0,mp);
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
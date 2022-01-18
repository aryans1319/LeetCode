// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int maxProfit(int price[],int currentIndex, int n,unordered_map<string,int>&mp){
        if(n==0){
            return 0;
        }
        
        if(currentIndex >= n){
            return 0;
        }
        
        string currentKey = to_string(currentIndex) + "_" + to_string(n);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int pick =0;
        int len =  (currentIndex+1);
        if(len <= n){
         pick = maxProfit(price, currentIndex,n-len,mp)+ price[currentIndex];
        }
        int notPick = maxProfit(price, currentIndex + 1, n,mp);
        mp[currentKey] = max(pick,notPick);
        return mp[currentKey] ;
    }
    int cutRod(int price[], int n) {
        unordered_map<string,int>mp;
       return maxProfit(price,0,n,mp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
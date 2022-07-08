// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ff first
#define ss second
class Solution{
public:
    // Iterative Solution
// Just normal matrix multiplication
// in code, ff means first , ss means second 

string matrixChainOrder(int p[], int n){
        
        pair<int , string> dp[n][n] ;
        
        for(int gap = 1 ; gap<n ; gap++){
            for(int i = 0 ; i<n - gap; i++){
                int j = i + gap ;
                if(gap == 1){
                    string res = "0" ;
                    res[0] = 'A' + i;
                    dp[i][j] = {0 , res} ; 
                }
                else{
                    dp[i][j] = {INT_MAX, "-1"} ;
                    for(int k = i+1 ; k<=j-1 ; k++){
                        int cost = p[i] * p[k] * p[j] + dp[i][k].ff + dp[k][j].ff ;
                        if(dp[i][j].ff > cost){
                           dp[i][j].ff = cost ; 
                           dp[i][j].ss = "(" + dp[i][k].ss + dp[k][j].ss + ")" ;
                        } 
                    }
                }
            }
        }
        
        return dp[0][n-1].second ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
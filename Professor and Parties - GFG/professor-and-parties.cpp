// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    
    string PartyType(long long int a[], int n)
    {
        set<long long int> s;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        if(s.size() == n){
            return "GIRLS";
        }
        return "BOYS";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        long long int a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        Solution ob;
        cout<< ob.PartyType(a, n) <<endl;
        
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalizeArray(int N, int k, int arr[]){
      long long  steps=0;
       sort(arr,arr+N);
       int mid=0;
       if(N%2==1){
           mid=N/2;
       }
       else{
           mid=N/2-1;
       }
       for(long long int i=0;i<N;i++){
   
           if(  (abs(arr[i]-arr[mid]))%k!=0){
               return -1;
           }
       }
       for(long long int i=0;i<N;i++){
       long long  diff=abs(arr[i]-arr[mid]);
           steps+=(diff/k)%1000000007;
       }
       return steps%1000000007;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, k;
        cin>>N>>k;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
            
        Solution ob;
        cout<<ob.equalizeArray(N, k, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
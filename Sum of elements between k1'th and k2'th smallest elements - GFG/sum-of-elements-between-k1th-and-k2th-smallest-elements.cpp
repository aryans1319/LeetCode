// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long sm = 0;
        long long first = kth_smallest(A,N,K1);
        long long sec = kth_smallest(A,N,K2);
        for(long long i=0;i<N;i++)
        {
            if( A[i] > first && A[i] < sec)
                sm += A[i];
        }
        return sm;
    }
    long long kth_smallest(long long a[],long long n,long long k)
    {
        priority_queue<long long>p;
        for(long long i=0;i<n;i++)
        {
            p.push(a[i]);
            if(p.size()>k)
            p.pop();
        }
        return p.top();
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
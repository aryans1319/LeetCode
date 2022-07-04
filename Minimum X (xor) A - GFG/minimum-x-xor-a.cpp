// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
         int c=0;
        while(b)
        {
            b=b&(b-1);
            c++;
        }
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(c<=0)
                break;
            if((a&(1<<i))>0)
            {
                c--;
                ans+=(1<<i);
            }
        }
        for(int i=0;i<31&&c>0;i++)
        {
            if((ans&(1<<i))==0)
            {
                ans+=(1<<i);
                c--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends
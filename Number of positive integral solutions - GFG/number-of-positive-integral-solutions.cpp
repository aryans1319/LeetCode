// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
   long int f(int var, int k)
    {
         if(var==k)
        {
            return 1;
        }
        if((var>k)||var==0)
        {
            return 0;
        }
        int ans=0;
       for(int i=1;i<=k;i++)
       {
           ans=ans+f(var-1,k-i);
       }
       return ans;
        
    }
    long posIntSol(string s)
    {
        int c=0,idx;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')
            {
                c++;
            }
            else if(s[i]=='=')
            {
                idx=i;
                break;
            }
        }
        int k;
        if(idx+1==n-1)
        {
            k=s[n-1]-'0';
        }
        else
        {
            k=(s[n-2]-'0')*10+(s[n-1]-'0');
        }
        //cout<<c+1<<" "<<k<<endl;
        long int ans=f(c+1,k);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
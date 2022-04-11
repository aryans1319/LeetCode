// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        vector<int> res;
        res.push_back(mp.size());
        
        int left = 0;
        for(int right = k;right <n;right++){
            if(mp.find(arr[right])!=mp.end()){
                mp[arr[right]]+=1;
            }
            else{
                mp[arr[right]] = 1;
            }
            if(mp.find(arr[left])!=mp.end()){
            mp[arr[left]]-=1;
            }
            else{
                mp[arr[left]]=1;
            }
            if(mp[arr[left]] == 0){
                mp.erase(arr[left]);
            }
            left++;
            res.push_back(mp.size());
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
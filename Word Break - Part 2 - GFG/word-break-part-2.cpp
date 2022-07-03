// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 vector<string> ans;
    void solve(int last, int index, string &s, vector<string> make, unordered_map<string, int> &mp)
    {
        if (index == s.size())
        {
            string curr;
            for (int i = 0; i < make.size(); i++)
            {
                if (i == make.size() - 1)
                    curr += make[i];
                else
                    curr += make[i] + ' ';
            }
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            string temp = s.substr(last, i - last + 1);
            if (mp[temp])
            {
                make.push_back(temp);
                solve(i + 1, i + 1, s, make, mp);
                make.pop_back();
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_map<string, int> mp;
        for (auto i : dict)
            mp[i] = 1;

        vector<string> make;
        solve(0, 0, s, make, mp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
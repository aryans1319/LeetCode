class Solution {
public:
    set<int>st;
    void solve(int indx,int n,int k,string s)
    {   
        if(indx==n)
        {
            st.insert(stoi(s));
            return;
        }
        if(indx==0)
        {
            for(int i=1;i<10;i++)
            {
                s+=to_string(i);
                solve(indx+1,n,k,s);
                s.pop_back();
            }
        }
        else
        {
            char ch=s.back();
            int val=ch-'0';
            if(val+k<10)
            {
                s+=to_string(val+k);
                solve(indx+1,n,k,s);
                s.pop_back();
            }
            if(val-k>=0)
            {
                s+=to_string(val-k);
                solve(indx+1,n,k,s);
                s.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        solve(0,n,k,"");
        vector<int>ans;
        for(auto x:st)
            ans.push_back(x);
        return ans;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& items, int n) {
        vector<int> v;
        map<int,int> mp;   
        for(auto x:items)  
            mp[x]++;  
        for(auto x:mp) 
            v.push_back(x.second); 
        sort(v.begin(),v.end()); 
        int i=0;
        for(i=0;i<v.size();i++)
        {
            if(n>=v[i])  
            {
              n-=v[i]; 
            } 
            else break; 
        }
        return v.size()-i;
    }
};
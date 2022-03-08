#include<bits/stdc++.h>
using namespace std;

vector<int>sortFreq(vector<int>&a,int n){
    unordered_map<int,int>mp;
    vector<int>ans;
    for(auto it : a){
        mp[it]++;
    }
    
    priority_queue<pair<int,int>>maxH;
    for(auto it : mp){
        maxH.push({it.second,(-1)*it.first});
    }
    
    while(maxH.size() > 0){
        int freq = maxH.top().first;
        int elem = maxH.top().second;
        
        for(int i = 1;i<= freq;i++){
            ans.push_back((-1)*elem);
        }
        maxH.pop();
    }
    return ans;
}


int main()
 {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<int>v = sortFreq(a,n);
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int ans=0;
void dfs(int i, vector<int> &visit, vector<int> l[], int d){
    if(i==d){
        ans++;
        return;
    }
    
    visit[i]=1;
    for(auto x:l[i]){
        if(!visit[x]){
            dfs(x, visit, l, d);
        }
    }
    visit[i]=0;
}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    ans=0;
	    vector<int> l[n];
	    for(auto x:edges){
	        l[x[0]].push_back(x[1]);
	    }
	    vector<int> visit(n, 0);
	    dfs(s, visit, l, d);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
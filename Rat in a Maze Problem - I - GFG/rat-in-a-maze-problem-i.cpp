// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        vector<string>ans;
        generateAllPaths(grid,0,0,n,"",ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void generateAllPaths(vector<vector<int>>&grid,int currentRow,
    int currentCol,int n,string current, vector<string>&ans){
        
        if(currentRow < 0 || currentRow >= n || currentCol>=n || currentCol<0
        || grid[currentRow][currentCol]==0){
            return;
        }
        
        if(currentRow == n-1 && currentCol == n-1)
        {
            ans.push_back(current);
            return;
        }
        
        grid[currentRow][currentCol] = 0;
        
        // moving up
        generateAllPaths(grid, currentRow-1, currentCol,n,current+"U",ans);
        
        //right move
        generateAllPaths(grid, currentRow, currentCol+1,n,current+"R",ans);
        
        //down move
        generateAllPaths(grid, currentRow+1, currentCol,n,current+"D",ans);
        
        //left move
        generateAllPaths(grid, currentRow, currentCol-1,n,current+"L",ans);
        
        grid[currentRow][currentCol] = 1;
        return;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
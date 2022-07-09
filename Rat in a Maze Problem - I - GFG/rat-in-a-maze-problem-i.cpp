// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findValidPath(vector<vector<int>> &grid, int row, int col, int n, string currentPath, vector<string>&ans){
        if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] <= 0) {
            return;
        }
        
        if(row == n-1 && col == n-1){
            ans.push_back(currentPath);
        }
        
        grid[row][col] = -1;
        
        // down
        findValidPath(grid,row+1,col,n,currentPath + "D",ans);
        
        //left
        findValidPath(grid,row,col-1,n,currentPath + "L",ans);
        
        //right
        findValidPath(grid,row,col+1,n,currentPath + "R",ans);
        
        //up
        findValidPath(grid,row-1,col,n,currentPath + "U",ans);
        
        grid[row][col] = 1;
        return;
    }
    
    
    vector<string> findPath(vector<vector<int>> &grid, int n) {
       vector<string>ans;
       findValidPath(grid,0,0,n,"",ans);
       return ans;
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
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
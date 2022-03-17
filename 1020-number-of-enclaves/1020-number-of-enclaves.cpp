class Solution {
public:
  int rows, cols;
 	void dfs(vector<vector<int>>& A, int i, int j) {
 		if (i < 0 || j < 0 || i >= rows || j >= cols)
 			return;

 		if (A[i][j] != 1) 
 			return;

 		A[i][j] = -1;
 		dfs(A, i+1, j);
 		dfs(A, i-1, j);
 		dfs(A, i, j+1);
 		dfs(A, i, j-1);
 	}
    
    int numEnclaves(vector<vector<int>>& A) {
        
        if (A.empty()) return 0;

 		rows = A.size();
 		cols = A[0].size();
 		for (int i = 0; i < rows; i++) {
 			for (int j = 0; j < cols; j++) {
 				if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
 					dfs(A, i, j);
 			}
 		}

 		int ans = 0;
 		for (int i = 0; i < rows; i++) {
 			for (int j = 0; j < cols; j++) {
 				if (A[i][j] == 1)
 					ans++;
 			}
 		}

 		return ans;
    }
};
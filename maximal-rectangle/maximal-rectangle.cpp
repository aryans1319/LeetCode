class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(n + m == 2) return matrix.front().front() == '1';
		
		//dp to store max number of adjacent 1s on left for each matrix[ i ][ j ]
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1] != '0')
                  dp[i][j] = 1 + dp[i][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
		
		//variable to store answer
        int area = 0;
		
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
			//variable to store current width of rectangle of size 1 * dp[i][j]
                int width = dp[i][j];
                int k = i-1;
                int height = 1;
                area = max(area,width * height);
				
				//now we'll start moving upwards as long as we are inside the matrix
				//ans change the height ans width accordingly to find the largest
				//area which can be achieved including current element
				//height always increases as we go up, width of rectangle till that height changes
				//to minimum no. of left 1s for every upward element
                while(k > 0 and dp[k][j] > 0)
                {
                    height++;
                    width = min(width,dp[k--][j]);
					//for every acceptable height, we check if it can be our answer
                    area = max(width * height,area);
                }
            }
        }
        
        return area;
    }
};
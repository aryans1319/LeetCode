class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        dfs(image,sr,sc,image[sr][sc],image.size(),image[0].size(),newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image,int currentRow,int currentCol,int color,int m,int n,int newColor){
        if(currentRow < 0 || currentRow >=m || currentCol < 0 || currentCol >=n || image[currentRow][currentCol]!=color){
            return;
        }
        image[currentRow][currentCol] = newColor;
        
        // up move
        dfs(image,currentRow - 1,currentCol,color,m,n,newColor);
        
        // down move
        dfs(image,currentRow + 1,currentCol,color,m,n,newColor);
        
        //right move
        dfs(image,currentRow,currentCol+1,color,m,n,newColor);
        
        //left move
        dfs(image,currentRow,currentCol-1,color,m,n,newColor);
        
        return;
    }
};
class Solution {
public:
    int minSum(vector<vector<int>>&triangle, int cI, int cJ, vector<vector<int>>&v){
        
        if(cI == triangle.size() || cJ == triangle.size()){
            return 0;
        }
        
        if(v[cI][cJ]!=-1){
            return v[cI][cJ];
        }
        
        int moveRow = minSum(triangle, cI+1,cJ,v);
        int moveBoth = minSum(triangle, cI+1, cJ+1,v);
        
        v[cI][cJ] = min(moveRow , moveBoth) + triangle[cI][cJ];
        
        return   v[cI][cJ];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int i = triangle.size();
        int j = i;
            
        vector<vector<int>> v(i, vector<int> (j,-1));
        
        return minSum(triangle,0,0,v);   
    }
};
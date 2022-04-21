class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; i++){
            int start = 0;
            int end = n-1;
            while(start < end){
                int temp = image[i][start];
                image[i][start] = image[i][end];
                image[i][end] = temp;
                start++;
                end--;
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0; j < image[i].size();j++){
                if(image[i][j] == 0){
                    image[i][j] = 1;
                }
                else if(image[i][j] == 1){
                    image[i][j] = 0; 
                }
            }
        }
        return image;
    }
};
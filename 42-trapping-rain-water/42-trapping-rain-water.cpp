class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
        int water=0;
        int left=0,right=n-1;
        int maxL=0,maxR=0;
        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left] > maxL) maxL = height[left];
                else water += maxL - height[left];
                left++;
            }
            else{
                if(height[right] > maxR) maxR = height[right];
                else water += maxR - height[right];
                right--;
            }
        }
        return water;        

    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,max_a=0;
        
        while(l<=r){
            int lh=height[l];
            int rh=height[r];
            int min_hi=min(lh,rh);
            max_a=max(max_a,min_hi*(r-l));
            if(lh<rh) l++;
            else r--;
        }
        return max_a;
    }
};
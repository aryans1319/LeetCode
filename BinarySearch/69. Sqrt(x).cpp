class Solution {
public:
    int mySqrt(int x) {
        long l= 0 , h =x,ans=0;
        while(l <= h)
        {
            long mid = ( l+h)/2;
            if( x >= mid * mid )
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                h = mid -1;
            }
                
        }
        return ans;
    }
};

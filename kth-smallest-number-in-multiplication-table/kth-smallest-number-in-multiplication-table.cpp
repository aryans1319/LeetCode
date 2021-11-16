class Solution {
public:
    int findKthNumber(int m, int n, int k) {
           int lo=0, hi=m*n;
        while (lo < hi) {
            int mid=(lo+hi)/2, count=0;
            // check how many numbers are smaller than mid
            for (int i=1; i<=m; i++)
                count += n < mid/i ? n : mid/i;
            if (count >= k)  // target <= mid
                hi = mid;
            else  // target > mid
                lo = mid+1;
        }
        return lo;
    }
};
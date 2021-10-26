class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int l = 0 , h= A.size()-1 , ans = -1;
        while( l <= h)
        {
            int mid = ( l+ h)/2;
            if( A[mid] == target )
            {
                ans = mid;
                h = mid-1;
            }
            else if ( A[mid] > target )
                h = mid -1;
            else
                l = mid + 1;
        }
        vector<int> res;
        res.push_back(ans);
        l = 0 , h= A.size()-1 , ans = -1;
        while( l <= h)
        {
            int mid = ( l+ h)/2;
            
            if( A[mid] == target )
            {
                ans = mid;
                l = mid+ 1;
            }
            else if ( A[mid] > target )
                h = mid -1;
            else
                l = mid + 1;
        }
        res.push_back(ans);
        return res;
    }
};

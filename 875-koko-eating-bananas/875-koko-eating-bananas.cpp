class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        
        // number lies between min and max-element
        for(auto x : piles){
            high = max(x,high);
        }
        
        int val = 0;
        while(low<high){
            int mid = (low+high)/2; val = 0;
            // calculate val for each mid assumed
			// this loops tell the time taken to eat all bananas by the current mid
            for (auto x : piles) val += (x+mid-1)/mid; 
            // if the time is less than the value given to us we reduce the high as we need 
			// to increase time by decreasing high we increase time
            if (val <= h) high = mid; 
            
            else low = mid+1; 
        }
        return low;
    }
};
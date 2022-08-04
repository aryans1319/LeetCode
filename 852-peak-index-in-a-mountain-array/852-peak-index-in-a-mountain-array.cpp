class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = arr.size() - 1;
        // if(arr.size() == 1) return 0;
        // if(arr[0] > arr[1]) return 0;
        // if(arr[n-1] > arr[n-2]) return n-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            /*
            We are at the decreasing part of the array
            ans would lies in the left part of the array but
            mid can also be a possible value so we reduced
            our search space start to mid
            */
            if(arr[mid] > arr[mid+1]){
                end = mid;
            }
             /*
            We are at the increasing part of the array
            ans would lies in the right part of the array
            update start to mid+1, since we compare 
            arr[mid+1] > arr[mid] so obviously mid cant be the max
            element so search space reduced to mid+1 to end
            */
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
};
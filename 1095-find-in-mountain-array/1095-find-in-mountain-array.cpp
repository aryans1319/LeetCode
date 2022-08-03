/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakElement(MountainArray &arr) {
        int n = arr.length();
        if(arr.length() == 1) return 0;
        if(arr.get(0) > arr.get(1)) return 0;
        if(arr.get(n-1) > arr.get(n-2)) return n-1;
        
        int start = 0;
        int end = arr.length() - 1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr.get(mid+1) < arr.get(mid) && arr.get(mid) > arr.get(mid-1)){
                return mid;
            }
            /*
            We are at the decreasing part of the array
            ans would lies in the left part of the array but
            mid can also be a possible value so we reduced
            our search space start to mid
            */
             if(arr.get(mid) > arr.get(mid+1)){
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
    int OrderAgnosticBinarySearch(MountainArray arr, int target, int start, int end){

        bool isAsc = arr.get(start) < arr.get(end);

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr.get(mid) == target) return mid;

            if(isAsc){
                if(arr.get(mid) < target) start = mid + 1;
                else end = mid - 1;
            }else{
                if(arr.get(mid) > target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeakElement(mountainArr);
        int firstTry = OrderAgnosticBinarySearch(mountainArr, target, 0, peak);
        if(firstTry == -1){
            return OrderAgnosticBinarySearch(mountainArr, target, peak+1, mountainArr.length()-1);
        }
        return firstTry;
    }
};
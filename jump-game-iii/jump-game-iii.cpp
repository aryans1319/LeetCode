class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
          if(arr[start]==0){
            return true;
        }
        
        int new_index=start+arr[start];
        int new_index1=start-arr[start];
        arr[start]=-1; // for marking visited
        
        if(new_index<arr.size() && arr[new_index]!=-1 && canReach(arr,new_index))
            return true;
        
        if(new_index1>=0 && arr[new_index1]!=-1 && canReach(arr,new_index1))
            return true;
        return false;
    }
};
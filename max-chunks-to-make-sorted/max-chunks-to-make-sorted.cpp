class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0) return 0;
      vector<int> maxArray(arr.size());
        maxArray[0] = arr[0];
        for(int i= 1;i<arr.size();i++){
            maxArray[i] = max(maxArray[i-1],arr[i]); 
        }
        int count = 0;
        for(int i = 0 ; i<maxArray.size();i++){
            if(maxArray[i] == i)
                count++;
        }
        return count;
    }
};
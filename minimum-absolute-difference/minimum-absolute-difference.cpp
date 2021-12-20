class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>mindif;
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            mini = min(mini,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i]-arr[i+1])==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};
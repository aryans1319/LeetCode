class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers){
        double n = customers.size();
        // double m = customers[0].size();
        int time =0;
        double total = 0;
        for(int i=0;i<n;i++){
            time = max(customers[i][0],time) + customers[i][1];
            total += time - customers[i][0];
        }
        // cout<<total<<" ";
        return (double)(total/n);
    }
};
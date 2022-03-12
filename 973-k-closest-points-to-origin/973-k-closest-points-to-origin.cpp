class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        // vector<pair<int,int>>currentAns;
        priority_queue<pair<int,pair<int,int>>>maxH;
        for(int i=0;i<points.size();i++){
            maxH.push({points[i][0] * points[i][0] + points[i][1] * points[i][1] , {points[i][0],points[i][1]}});
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        while(maxH.size() > 0){
            // currentAns.push_back(maxH.top().second);
            ans.push_back({maxH.top().second.first,maxH.top().second.second});
            maxH.pop();
        }
        return ans;
    }
};
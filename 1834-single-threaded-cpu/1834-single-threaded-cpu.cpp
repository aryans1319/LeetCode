class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
          vector<int>ans;
        
        for(int i=0;i<tasks.size();i++){
            
            tasks[i].push_back(i);
            
        }
        sort(tasks.begin(),tasks.end());
//         
        vector<int>flag(tasks.size());
        long long start=1,i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(i<tasks.size()){
        
            for(;i<tasks.size()&&tasks[i][0]<=start;i++){
                pq.push({tasks[i][1],tasks[i][2]});
            }
            if(pq.empty()){
                ans.push_back(tasks[i][2]);
                start=tasks[i][1]+tasks[i][0];
                i++;
            }
            else{
                ans.push_back(pq.top().second);
                start+=pq.top().first;
                pq.pop();

            }
            
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
                start+=pq.top().first;
                pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      /*----------Connecting edges----------*/
        vector<int>adj[numCourses];
        int n = numCourses;
        vector<int>inDegree(n,0);
        
        for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);  
            inDegree[it[0]]++;
        }
        
        /*----------TOPO SORT--------------*/
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]!=0){
                vector<int>dummy;
                    return dummy;
            }
        }
        
        return ans;
    }
};
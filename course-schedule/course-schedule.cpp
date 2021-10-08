class Solution {
private:     
    
    //Cycle Detection Concept
    
    bool dfsCycle(int node, vector<int>&vis, vector<int> &pathVis, vector<int>adj[]){
    vis[node]=1;
    pathVis[node]=1;
    
    for(auto it:adj[node]){
        if(vis[it]==0){
            if(dfsCycle(it,vis,pathVis,adj)==true)return true;
        }
        else if(pathVis[it]==1){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}   
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0), pathVis(numCourses,0);
        vector<int>adj[numCourses];
        
        //making a graph and connecting edges from B[i] to A[i]
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        /*
        checking if there is a cycle in the graph if detected then not possible
        to finish all courses.
        */
       
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCycle(i,vis,pathVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    void sourceToTarget(vector<vector<int>>&graph, int currentNode,vector<bool>visited,int n , vector<int>&currentPath,vector<vector<int>>&answer){
        if(currentNode == n-1){
            currentPath.push_back(currentNode);
            answer.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        
        if(visited[currentNode] == true){
            return;
        }
        
        visited[currentNode] = true;
        currentPath.push_back(currentNode);
        
        for(auto neighbour : graph[currentNode]){
            sourceToTarget(graph,neighbour,visited,n,currentPath,answer);
        }
        
        visited[currentNode] = false;
        currentPath.pop_back();
        return;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>answer;
        vector<int>currentPath;
        int n = graph.size();
        vector<bool> vis(n);
        sourceToTarget(graph,0,vis,n,currentPath,answer);
        return answer;
        }
};
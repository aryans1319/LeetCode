class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++)
        {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
            
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        while(!q.empty()){
            auto currentNode = q.front();
            q.pop();
            if(visited[currentNode])
                continue;
            if(currentNode == destination)
                return true;
            visited[currentNode] = true;
            
            for(auto neighbour : graph[currentNode]){
                q.push(neighbour);
            }
        }
        return false;
    }
};
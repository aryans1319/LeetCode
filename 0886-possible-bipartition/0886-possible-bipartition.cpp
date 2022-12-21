class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<int> edges[n+1];
        for (auto elem : dislikes) {
            edges[elem[0]].push_back(elem[1]);
            edges[elem[1]].push_back(elem[0]);
        }
        
        vector<int> color(n+1, -1);
        
        for (int i=1; i<=n; i++) {
            if (color[i] == -1) {
                queue<pair<int, int>> Q;
                Q.push({i, 1});
                
                while(!Q.empty()) {
                    pair<int, int> tmp = Q.front();
                    Q.pop();
                    if (color[tmp.first] == tmp.second)
                        continue;
                    if (color[tmp.first] == -1)
                        color[tmp.first] = tmp.second;
                    if (color[tmp.first] != tmp.second)
                        return false;
                    for (auto elem : edges[tmp.first])
                        Q.push({elem, 1 - tmp.second});
                }
            }
        }
        
        return true;
    }
};
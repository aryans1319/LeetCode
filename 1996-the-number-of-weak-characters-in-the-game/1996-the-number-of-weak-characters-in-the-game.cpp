class Solution {
public:
    static bool sortAccordingly(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0]<b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int count = 0;
        sort(properties.begin(),properties.end(),sortAccordingly);
        
        int maxDefence = 0;
        
        for(int i = n-1;i>=0;i--){
            if(properties[i][1] < maxDefence) count++;
            maxDefence = max(maxDefence,properties[i][1]);
        }
        return count;
    }
};
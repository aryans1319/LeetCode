class Solution {
public:
    /*
Algorithm:
----------------------------------------------------------------------------------------
1. Simple `backtracking` approach. 
2. The idea is to add characters one by one of the input string (tiles) to a temporary
   string which is further added to a HashSet to avoid repeatation. 
3. While doing so the characters which are once visited should be skipped for that 
   maintain a `visited` array of size same as that of the entire string.
4. In each recursion call, add the temporary strings into the HashSet.
5. When the recursion call is over, the set is filled with all strings, which includes
   the `null` as well.
6. Hence return the size of the set -1. That `-1` corresponds to the `null` string. 
----------------------------------------------------------------------------------------
*/

    void findCombinations(string tiles, string currentString, set<string>&set, vector<bool>&vis){
        set.insert(currentString);
        for(int i=0;i<tiles.size();i++){
            if(!vis[i]){
                vis[i] = true;
                findCombinations(tiles,currentString+tiles[i], set, vis);
                vis[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool>vis(n);
        set<string>st;
        findCombinations(tiles,"",st,vis);
        return st.size()-1;
    }
};
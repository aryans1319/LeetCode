class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        bool flag;
        unordered_set<int>s;
        // Count Frequency of each elements in a Map
        for(auto i:arr){
            mp[i]++;
        }
        /* Iterate through the map and insert the key's value pair in a set.
            We are doing this so that it stores only unique values which set does.
            
            For eg: Look at Example 1, 1->3
                                       2->2 
                                       3->1
                                       insert the values in set s[1,2,3](values in set)
                                       compare them with map size they are equal hence mark
                                       flag as true.
                    
                    Example 2,         1->1
                                       2->1
                                       
                                       if we insert values of key in set it would store only 1
                                       (because set stores only unique values) therefore set size
                                       equals 1 but mp has size 2 so mark flag as false.
         
         I hope it's clear now if you any doubt comment them below.                                       
         */

  for (auto& p : mp)
      if (!s.insert(p.second).second) return false;
  return true;
    }
};
class Solution {
public:
      vector<vector<int>>ans;
    void combo(int ind,int k,vector<int>&current,int n){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        
        for(int i=ind;i<n+1;i++){
            current.push_back(i);
            combo(i+1,k,current,n);
            current.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        combo(1,k,current,n);
        return ans;
    
    } 
};
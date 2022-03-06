class Solution {
public:
     
         int fun (vector <int> &a, int n, int counter,unordered_map<int,int>&mp)
    {
        if (n < 3) return 0;
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }     
             
        if (a[n-1] + a[n-3] == 2 * a[n-2]) { 
            counter ++; 
            return mp[n] = counter + fun (a, n-1, counter,mp);
        }
        else{
            return mp[n] = fun (a, n-1, 0,mp);
        }
    }
    
    
    int numberOfArithmeticSlices(vector<int>& nums) {
          unordered_map<int,int>mp;
          return fun(nums, nums.size(), 0, mp);
}
};
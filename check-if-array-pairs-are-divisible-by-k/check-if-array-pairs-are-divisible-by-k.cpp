class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>memo;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int currentVal = arr[i];
            int currentRem = ((currentVal % k) + k) % k;
            
            if(memo.find(currentRem) != memo.end()){
                memo[currentRem] += 1;
            }
            else{
                memo[currentRem] = 1;
            }
        }
        
        for(auto key: memo){
            if(key.first==0){
                if(memo[key.first]%2!=0){
                    return false;
                }
            }
            else if(memo.find(k-key.first)==memo.end()){
                return false;
            }
            else if(memo[key.first]!=memo[k-key.first]){
                return false;
            }
        }
        return true;
    }
};
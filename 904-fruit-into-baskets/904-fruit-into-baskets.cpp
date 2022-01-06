class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int mx = 0;
        int k=2;
        
        if(fruits.size()==1){
            return 1;
        }
        
    unordered_map<int,int> memo;
    while(j<fruits.size()){
        memo[fruits[j]]++;
        // if(memo.size()<k){
        //     j++;
        // }
        if(memo.size()<=k){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(memo.size()>k){
            while(memo.size()>k){
                memo[fruits[i]]--;
                if(memo[fruits[i]]==0)
                {
                    memo.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;

    }
};
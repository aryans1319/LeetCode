class Solution {
public:
    int minimumRecolors(string blocks, int k) {   
        int i = 0;
        int j = 0;
        int n = blocks.size();
        int c=0;
        int ans = n;
        while(j < n){
            if(blocks[j] == 'W'){
                c++;
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans = min(ans, c);
                if(blocks[i] == 'W'){
                    c--;
                }
                            i++;j++;
            }

        }
        return ans;
    }
    
};
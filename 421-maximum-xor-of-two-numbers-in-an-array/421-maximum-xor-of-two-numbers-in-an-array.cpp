class Solution {
public:
    int xor_arr(vector <int> & nums){
        int mx = 0;
        //Max Value
        int mask = 0;
        // Prefix Mask -> 10000, 11000, 11100, 11110, 11111
        set <int> se;
        
        for(int bit=30;bit >=0;--bit){
            mask |= (1 << bit);
            for(int i=0;i<nums.size();++i){
                se.insert(nums[i] & mask);
                //this is important such that binary representation of num (from nums) only includes till
                //ith bit.
            }
            
            int newMax = mx | (1 << bit);
            // Check whether we can improve mx value by turning on the ith bit in mx
            // such that newMax is obtained
            // if a^b = x then a^x = b;
            for(auto prefix : se){
                
               if(se.count(newMax ^ prefix)){
                    mx = newMax;
                    break;
                }
            }
            
            se.clear();
        }
        return mx;
    }
    int findMaximumXOR(vector<int>& nums) {
        return xor_arr(nums);
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
          int i=0,j=0,sum=0,s=0;
            unordered_map<int,int>mp;
            bool duplicateHai = false;
            while(j<nums.size())
            {
                    mp[nums[j]]++;
                    sum=sum+nums[j];
                    
                    if(mp[nums[j]] > 1){
                         duplicateHai = true;
                    }
                    while(duplicateHai == true){
                        int currentVal = nums[i];
                        if(mp[currentVal] > 1){
                             duplicateHai = false;
                        }
                             mp[currentVal]--;
                              sum=sum-nums[i];
                            i++;

                        }
                    s= max(s,sum);
                    j++;
            }
            return s;
    }
};
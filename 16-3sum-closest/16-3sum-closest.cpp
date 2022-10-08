class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=INT_MAX;
        int ans=0;
        int temp;
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                temp=nums[left]+nums[right]+nums[i];
                if(abs(target-temp)<diff){
                    ans=temp;
                    diff=abs(target-temp);
                }
                if(temp==target)return temp;
                if(temp>target)right--;
                else left++;
            }
        }
        return ans;
    }
    
};
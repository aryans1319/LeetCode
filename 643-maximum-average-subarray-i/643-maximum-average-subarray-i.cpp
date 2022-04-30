class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
            double mas=0;
            double mx=INT_MIN;
            while(j<nums.size())
            {
                    mas=mas+nums[j];
                    if(j-i+1<k){
                            j++;
                    }
                    else if(j-i+1==k)
                    {
                            double x = mas/k;
                            mx= max(mx,x);
                            mas=mas-nums[i];
                            i++;
                            j++;
                    }
            }
            return mx;
    }
};
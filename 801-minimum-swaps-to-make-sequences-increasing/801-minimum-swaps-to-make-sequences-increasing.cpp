class Solution {
public:
int minOperations(vector<int>&nums1, vector<int>&nums2,int currentIndex,bool ifSwap,vector<vector<int>>&mp)
{
    if(currentIndex == nums1.size()) return 0;
    
    int prevElementOfNums1 = nums1[currentIndex-1];
    int prevElementOfNums2 = nums2[currentIndex-1];
    
    if(ifSwap==true){
        swap(prevElementOfNums1,prevElementOfNums2);
    }
    
    if(mp[currentIndex][ifSwap]!=-1){
        return mp[currentIndex][ifSwap];
    }
    
    int ans = INT_MAX;
    //not swap if already in increasing order
    if(nums1[currentIndex] > prevElementOfNums1 && nums2[currentIndex] > prevElementOfNums2){
        ans = minOperations(nums1,nums2,currentIndex+1,false,mp);
    }
    //swap if not in increasing order
    if(nums1[currentIndex] > prevElementOfNums2 && nums2[currentIndex] > prevElementOfNums1){
        int swapped = 1 + minOperations(nums1,nums2,currentIndex+1,true,mp);
        ans = min(ans,swapped);
    }
    mp[currentIndex][ifSwap] = ans;
    return mp[currentIndex][ifSwap];
    
}
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>mp(nums1.size()+1,vector<int>(2,-1));
        int swap = 1+ minOperations(nums1,nums2,1,1,mp);
        int notSwap = minOperations(nums1,nums2,1,0,mp);
        return min(swap,notSwap);
    }
};
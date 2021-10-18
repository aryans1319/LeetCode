class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
    // Brute force approach Time O(NlogN) & Auxiliary Space O(1)
    // Just overwrite nums2 on nums1 starting 
    // from the point where non zero element ends in nums1 
    for(int i=m;i<m+n;i++){
        nums1[i]=nums2[i-m];
    }
    // Sort function has O(NlogN) time complexity
        sort(nums1.begin(),nums1.end()); 
    
     
    }
};
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        vector<int>v;
      
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                for(int k=0;k<nums3.size();k++){
                    if(nums1[i]==nums2[j] || nums1[i]==nums3[k]){
                        ans.push_back(nums1[i]);
                    }
                    if(nums2[j]==nums1[i] || nums2[j]==nums1[i]){
                        ans.push_back(nums2[j]);
                    }
                    if(nums3[k]==nums2[j] || nums3[k]==nums1[i]){
                        ans.push_back(nums3[k]);
                    }
                             
                }
            }
        }
    sort( ans.begin(), ans.end() , greater<int>() );
ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;        
    }
};
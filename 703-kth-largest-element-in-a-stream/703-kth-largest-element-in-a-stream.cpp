class KthLargest {
    priority_queue<int,vector<int>,greater<int>>p;
    int v;
public:
    KthLargest(int k, vector<int>& nums) {
        v=k;
        if(nums.size()<=k){
            for(int i=0;i<nums.size();i++){
                p.push(nums[i]);
            }
        }
        else{
            sort(begin(nums),end(nums));
            for(int i=nums.size()-1,a=0;a<k;a++,i--)
            {
                p.push(nums[i]);
            }      
        }
    }
    
    int add(int val) {
        if(p.size()<v){
            p.push(val);
        }
       else {if(val>p.top()){
            p.pop();
            p.push(val);
           
        }}
         return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
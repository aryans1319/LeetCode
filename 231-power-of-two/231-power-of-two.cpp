class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        
        if(n%2!=0){
            return false;
        }
        
        return isPowerOfTwo(n/2);
    }
};

// time complexity : O(logn with base 2)
// Space :  O(logn with base 2)   
class Solution {
public:
    int nthFibonacci(int n,unordered_map<int,int>&mp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        int currentKey = n;
        
        if(mp.find(currentKey)!= mp.end()){
            return mp[currentKey];
        }
        
        int leftCall = nthFibonacci(n-1,mp);
        int rightCall = nthFibonacci(n-2,mp);
        
        mp[currentKey] =  leftCall + rightCall;
        
        return mp[currentKey] ;
        
    }
    int fib(int n) {
        unordered_map<int,int>mp;
        return nthFibonacci(n,mp);
    }
};
class Solution {
public:
    int nthFibonacci(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        int leftCall = nthFibonacci(n-1);
        int rightCall = nthFibonacci(n-2);
        
        return leftCall + rightCall;
        
    }
    int fib(int n) {
        return nthFibonacci(n);
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0){
            n = abs(n);
            x = 1/x;
        }
        double temp = myPow(x,n/2);
        if(n % 2 == 0){
            return temp*temp;
        }
        return x*temp*temp;
    }
};
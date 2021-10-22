class Solution {
public:
    double help(double x,int n){
        if(n==0) return 1;
        double ans=help(x,n/2);
        ans*=ans;
        if(n%2==1){
            ans*=x;
        }
        return ans;
    }
    
    double myPow(double x, int n) {
        if(n==INT_MIN) n=INT_MIN+2;
        double ans=help(x,abs(n));
        if(n<0) return 1/ans;
        else return ans;
    }
};
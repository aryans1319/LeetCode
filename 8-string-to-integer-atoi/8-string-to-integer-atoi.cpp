class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;
        int i = 0;
        // to eliminate empty spaces before string for eg : "     42"
        while( i < s.size() && s[i] == ' '){
            i++;
        }
        s = s.substr(i);  // means everthing after spaces
        
        int sign = +1;
        long res = 0;
        
        if(s[0] == '-') sign = -1;
        
        int maxi = INT_MAX, mini = INT_MIN;
        
        /*
        case to handle negative if number is neg we 
        should start from index 0 else index 1
        */
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        while( i < s.size()){
            if(s[0] == ' ' || !isdigit(s[i])) break;
            res = res*10 + s[i]-'0';
            if(sign == -1 && -1*res < mini) return mini;
            if(sign == 1 && res > maxi) return maxi;
            
            i++;
        }
        return (int) (sign * res);
    }
};
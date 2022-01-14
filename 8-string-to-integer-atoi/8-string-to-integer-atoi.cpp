class Solution {
public:
    int myAtoi(string s) {
           int r = 0;
        stringstream ss;
        ss << s;
        ss >> r;
        return r;
    }
};
class Solution {
public:
    int bitwiseComplement(int n) {
         int c = 1; // c = pow(2, x) – 1; c is the smallest number >= N
    while (c < n) 
      c = (c << 1) | 1;
      //c = c*2 + 1;  same as above
    return n ^ c;  
    //return c - N; // also ok  
    }
};
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> v(60,0);
        for(int i=0;i<time.size();i++){
            int remainder = time[i]%60;
            if(remainder == 0)
                count+=v[0];
            else
                count+=v[60-remainder];
            
            v[remainder]++;
        }
        return count;
    }
};
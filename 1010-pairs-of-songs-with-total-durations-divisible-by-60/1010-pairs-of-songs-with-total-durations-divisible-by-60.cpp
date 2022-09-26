class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int>hash(60, 0);
        
        for(int i = 0; i < time.size(); i++){
            
            int howFarFromDivisibleby60 = time[i] % 60;
            
            // if howFarFromDivisibleby60 == 0 i.e already divisible add hash[0] where 0 is remainder
            
            if(howFarFromDivisibleby60 == 0){
                count += hash[0];
            }
            // add freq of remainder howFarFromDivisibleby60 if 100 then howFarFromDivisibleby60 = 20 
            else{
                count += hash[60 - howFarFromDivisibleby60];
            }
            hash[howFarFromDivisibleby60]++;
        }
        return count;
    }
};
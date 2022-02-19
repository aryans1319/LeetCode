class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>ans({});
        
        
        if(finalSum%2!=0){
            return ans;
        }
        long long currentSum = 0;
        long long currentIndex = 2;
		
        while((currentSum+currentIndex)<= finalSum)
        {
            ans.push_back(currentIndex);
            currentSum+=currentIndex;
            currentIndex+=2;
        }
		
		int lastElement = ans.size();
        ans[lastElement-1] += (finalSum-currentSum);
        return ans;
    }
};
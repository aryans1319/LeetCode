class Solution {
public:
    int maxProfit(vector<int>& P) {
         int n = size(P), i = 1, profit = 0, buy, sell;
        while(i < n) {
            // find lowest price to buy - local valley \U0001f4c9
            for(buy = P[i-1]; i < n && P[i] < buy; i++) 
                buy = P[i];    
            if(i >= n) break;      // break if no more days remaining
            // find highest price to sell - local peak  \U0001f4c8 
            for(sell = P[i]; i < n && sell < P[i]; i++)
                sell = P[i];    
            profit += sell - buy; // keep adding the \U0001f4b8
            i++;
        }
        return profit; 
    }
};
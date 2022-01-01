class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        else if (n == 0) return nums[0];
        
        // if "nums" is const, we can create a new vector instead
        nums.insert(nums.begin(), 1);
        nums.push_back(1); // now, balloons are from 1 to n
    
        vector<vector<int>> memo(n + 2, vector<int>((n + 2), -1));
        return calcIncome(nums, memo, 0, n + 1); 
    }
    
    // start index from 0 to n - 1, end index from 2 to n + 1
    int calcIncome(vector<int>& nums, vector<vector<int>>& memo, int start, int end)
    {
        if (memo[start][end] != -1)
            return memo[start][end];

        if (end - start == 1)
            memo[start][end] = 0;
        else
        {
            int income = 0;
            
            for (int i = start + 1; i < end; i++)
            {  
                income = max(income, calcIncome(nums, memo, start, i) + 
                    calcIncome(nums, memo, i, end) + nums[i] * nums[start] * nums[end]);
            }
            
            memo[start][end] = income;
        }
        
        return memo[start][end];
    }
};
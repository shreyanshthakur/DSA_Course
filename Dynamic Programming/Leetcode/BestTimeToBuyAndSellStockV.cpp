class Solution {
public:
    
    int solve (int index, int buy, vector<int>& prices, vector<vector<int> >& dp, int fee) {
        if (index == prices.size()) 
            return 0;
        
        if (dp[index][buy] != -1) 
            return dp[index][buy];
        
        int profit = 0;
        if (buy) {
            profit = max ( -prices[index] + solve(index+1, 0, prices, dp, fee), 0 + solve(index+1, 1, prices, dp, fee) );    
        }
        else {
            profit = max ( +prices[index] + solve(index+1, 1, prices, dp, fee) - fee, 0 + solve(index+1, 0, prices, dp, fee) );
        }
        return dp[index][buy] = profit;
    }
    int solveTabSO (vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> cur(2, 0);
        vector<int> next(2, 0);
        
        
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
               
                int profit = 0;
                if (buy) {
                    profit = max ( -prices[index] + next[0], 0 + next[1] );    
                }
                else {
                    profit = max ( +prices[index] + next[1] - fee, next[0] );
                }
                cur[buy] = profit;
               
            }
            next = cur;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int> > dp(n, vector<int>(2, -1));
        // return solve (0, 1, prices, dp, fee);
        
        return solveTabSO (prices, fee);
    }
};
class Solution {
public:
    
    int solve (int index, int buy, vector<int>& prices, vector<vector<vector<int> > >& dp, int limit) {
        if (index == prices.size()) 
            return 0;
        if (limit == 0)
            return 0;
        
        if (dp[index][buy][limit] != -1) 
            return dp[index][buy][limit];
        
        int profit = 0;
        if (buy) {
            profit = max ( -prices[index] + solve(index+1, 0, prices, dp, limit), 0 + solve(index+1, 1, prices, dp, limit) );    
        }
        else {
            profit = max ( +prices[index] + solve(index+1, 1, prices, dp, limit-1), 0 + solve(index+1, 0, prices, dp, limit) );
        }
        return dp[index][buy][limit] = profit;
    }
    int solveTab (vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) { //limit = 0 base case tha so no need to consider
                    int profit = 0;
                    if (buy) {
                        profit = max ( -prices[index] + dp[index+1][0][limit], 0 + dp[index+1][1][limit] );    
                    }
                    else {
                        profit = max ( +prices[index] + dp[index+1][1][limit-1], dp[index+1][0][limit] );
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solveTabSO (vector<int>& prices) {
        int n = prices.size();

        vector<vector<int> > cur(2, vector<int>(3, 0));
        vector<vector<int> > next(2, vector<int>(3, 0));
        
        
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) { //limit = 0 base case tha so no need to consider
                    int profit = 0;
                    if (buy) {
                        profit = max ( -prices[index] + next[0][limit], 0 + next[1][limit] );    
                    }
                    else {
                        profit = max ( +prices[index] + next[1][limit-1], next[0][limit] );
                    }
                    cur[buy][limit] = profit;
                }
                next = cur;
            }
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
//         vector<vector<vector<int> > > dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
//         return solve (0, 1, prices, dp, 2);
        
        // return solveTab (prices);
        return solveTabSO (prices);
    }
};
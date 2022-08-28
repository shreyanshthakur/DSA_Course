class Solution {
public:
    
    int solve (int index, int operationNo, int k, vector<int>& prices, vector<vector<int> >& dp) {
        if (index == prices.size()) 
            return 0;
        if (operationNo == 2*k)
            return 0;
        
        if (dp[index][operationNo] != -1)
            return dp[index][operationNo];
        
        int profit = 0;
        if (operationNo%2 == 0) {
            //buy allowed
            profit = max (-prices[index] + solve(index+1, operationNo+1, k, prices, dp), 
                         0 + solve (index+1, operationNo, k, prices, dp));
        }
        else {
            profit = max (+prices[index] + solve(index+1, operationNo+1, k, prices, dp), 
                         0 + solve (index+1, operationNo, k, prices, dp));
        }
        return dp[index][operationNo] = profit;         
    }
    
    int solveTabSO (vector<int>& prices, int k) {
        int n = prices.size();

        vector<vector<int> > cur(2, vector<int>(k+1, 0));
        vector<vector<int> > next(2, vector<int>(k+1, 0));
        
        
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) { //limit = 0 base case tha so no need to consider
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
        return next[1][k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2*k, -1));
        return solve (0, 0, k, prices, dp);
        // return solveTabSO (prices, k);
    }
};
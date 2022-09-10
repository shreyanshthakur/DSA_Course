class Solution {
public:
    
    int solve (int k, int canBuy, vector<int>& prices, int index, vector<vector<vector<int> > >& dp) {
        //base case
        if (k <= 0 || index >= prices.size()) 
            return 0;
        
        if (dp[index][canBuy][k] != -1) 
            return dp[index][canBuy][k];
        
        if (canBuy) {
            //max of buy , ignore
            //-prices because buying contributes in no loss
            return dp[index][canBuy][k] = max ( -prices[index] + solve(k, 0, prices, index+1, dp),
                        solve(k, 1, prices, index+1, dp) );
        }
        else {//max of sell , ignore
            return dp[index][canBuy][k] = max (prices[index] + solve (k-1, 1, prices, index+1, dp), 
                       solve (k, 0, prices, index+1, dp));
        }
    }
    int solveTab (vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(k+1, 0)));
        
        for (int index = n-1; index >= 0; index--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                for (int K = 1; K <= k; K++) {
                    if (canBuy) {
                    //max of buy , ignore
                    //-prices because buying contributes in no loss
                     dp[index][canBuy][K] = max ( -prices[index] + dp[index+1][0][K],
                                dp[index+1][1][K] );
                    }
                    else {//max of sell , ignore
                        dp[index][canBuy][K] = max (prices[index] + dp[index+1][1][K-1], 
                                   dp[index+1][0][K]);
                    }
                }
                
            }
        }
        return dp[0][1][k];
    }
    int solveTabSO (vector<int>& prices, int k) {
        int n = prices.size();
        vector<int> curCanBuy(k+1, 0);
        vector<int> curCannotBuy(k+1, 0);
        vector<int> nextCanBuy(k+1, 0);
        vector<int> nextCannotBuy(k+1, 0);
        
        for (int index = n-1; index >= 0; index--) {
            for (int canBuy = 0; canBuy < 2; canBuy++) {
                for (int K = 1; K <= k; K++) {
                    if (canBuy) {
                    //max of buy , ignore
                    //-prices because buying contributes in no loss
                     curCanBuy[K] = max ( -prices[index] + nextCannotBuy[K],
                                nextCanBuy[K] );
                    }
                    else {//max of sell , ignore
                        curCannotBuy[K] = max (prices[index] + nextCanBuy[K-1], 
                                   nextCannotBuy[K]);
                    }
                }
            }
            nextCanBuy = curCanBuy;
            nextCannotBuy = curCannotBuy;
        }
        return nextCanBuy[k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        // int canBuy = 1;
        // int n = prices.size();
        // vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(k+1, -1)));
        // return solve (k, canBuy, prices, 0, dp);
        
        // return solveTab (prices, k);
        
        return solveTabSO (prices, k);
    }
};
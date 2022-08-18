class Solution {
public:
    
    int solve (int n) {
        
        //base case
        if (n == 0)
            return 0;
        
        int ans = n; // 1 ke squares add krke n banado (max possible ans) 
        for (int i = 1; i*i <= n; i++) {
            ans = min(ans, solve (n - i*i) + 1);
        }
        
        return ans;
    }
    
    int solveMem (int n, vector<int> &dp) {
        
        //base case
        if (n == 0)
            return 0;
        
        if (dp[n] != -1) 
            return dp[n];
        
        int ans = n; // 1 ke squares add krke n banado (max possible ans) 
        for (int i = 1; i*i <= n; i++) {
            ans = min(ans, solveMem (n - i*i, dp) + 1);
        }
        dp[n] = ans;
        return dp[n];
    }
    
    int solveTab (int n) {
        //step 1: create dp array
        vector<int> dp(n+1, INT_MAX);
        
        //step 2: base case analyse and initialte dp array elements
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j*j <= n; j++) {
                if (i - j*j >= 0)
                    dp[i] = min (dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        
        // return solve (n);
        
        vector<int> dp(n+1, -1);
        return solveMem (n, dp);
        
        // return solveTab(n);
    }
};
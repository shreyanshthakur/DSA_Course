class Solution {
public://Bottom-Up Approach
    int fib(int n) {
        //step 1: Create a dp array
        vector<int> dp(n+1);
        //step 2: Initialise by analysing base cases
        dp[0] = 0;
        if (n == 0) 
            return dp[0]; //remember to corner cases
        dp[1] = 1;
        
        //step 3: Apply for loop by analysing work range
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
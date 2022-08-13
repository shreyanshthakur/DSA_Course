class Solution {
public:
    //bottom up approach
    //TC = O(n)
    //SC = O(n)
    int fibUtil (int n, vector<int> &dp) {
        if (n <= 1)
            return n;
        //step 3:
        if (dp[n] != -1)
            return dp[n];
        //step 2: 
        dp[n] = fibUtil(n-1, dp) + fibUtil(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        //step 1:
        vector<int> dp(n+1, -1);
        
        return fibUtil (n, dp);
    }
};
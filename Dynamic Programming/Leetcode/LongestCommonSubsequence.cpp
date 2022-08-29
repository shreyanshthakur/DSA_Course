class Solution {
public:
    int solve (string& a, string&b, int i, int j, vector<vector<int> >& dp) {
        //base case
        if (i == a.length())
            return 0;
        if (j == b.length())
            return 0;
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solve (a, b, i+1, j+1, dp);
        }
        else {
            ans = max (solve (a, b, i+1, j, dp), solve (a, b, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
    int solveTab (string& a, string&b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        
        for (int i = a.length()-1; i >= 0; i--) {
            for (int j = b.length()-1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + dp[i+1][j+1];
                }
                else {
                    ans = max (dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveTabSO (string a, string b) {
        vector<int> cur(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        
        for (int i = a.length()-1; i >= 0; i--) {
            for (int j = b.length()-1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max (next[j], cur[j+1]);
                }
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), -1));
        // return solve (text1, text2, 0, 0, dp);
        
        // return solveTab (text1, text2);
        // return solveTabSO (text1, text2);
        
        if (text1.length() > text2.length())
            return solveTabSO (text1, text2);
        return solveTabSO (text2, text1);
    }
};
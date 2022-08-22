class Solution {
public:
    
    int solve (int index, int endIndex, vector<int>& slices, int n) {
        //base case
        if (n == 0 || index >= slices.size())
            return 0;
        
        //eat
        int eat = slices[index] + solve (index+2, endIndex, slices, n-1);
        int noteat = solve (index+1, endIndex, slices, n);
        
        return max (eat, noteat);
    }
    int solveMem (int index, int endIndex, vector<int>& slices, int n, vector<vector<int> > &dp) {
        //base case
        if (n == 0 || index > endIndex)
            return 0;
        
        if (dp[index][n] != -1) 
            return dp[index][n];
        
        //eat
        int eat = slices[index] + solveMem (index+2, endIndex, slices, n-1, dp);
        int noteat = solveMem (index+1, endIndex, slices, n, dp);
        
        return dp[index][n] = max (eat, noteat);
    }
    int solveTab (vector<int>& slices) {
        int k = slices.size();
        vector<vector<int> > dp1(k+2, vector<int> (k+2, 0));
        
        for (int index = k-2; index >= 0; index--) {
            for (int n = 1; n <= k/3; n++) {
                int eat = slices[index] + dp1[index+2][n-1];
                int noteat = dp1[index+1][n];

                dp1[index][n] = max (eat, noteat);
            }
        }
        int case1 = dp1[0][k/3];
        
        vector<vector<int> > dp2(k+2, vector<int> (k+2, 0));
        for (int index = k-1; index >= 1; index--) {
            for (int n = 1; n <= k/3; n++) {
                int eat = slices[index] + dp2[index+2][n-1];
                int noteat = dp2[index+1][n];

                dp2[index][n] = max (eat, noteat);
            }
        }
        int case2 = dp2[1][k/3];
        
        return max (case1, case2);
    }
    int solveTabSO (vector<int>& slices) {
        int k = slices.size();
        
        //case 1: first slice include last slice dropped
        vector<int> prev1(k+2, 0);
        vector<int> cur1(k+2, 0);
        vector<int> next1(k+2, 0);
        
        for (int index = k-2; index >= 0; index--) {
            for (int n = 1; n <= k/3; n++) {
                int eat = slices[index] + next1[n-1];
                int noteat = cur1[n];

                prev1[n] = max (eat, noteat);
            }
            next1 = cur1;
            cur1 = prev1;
        }
        int case1 = cur1[k/3];
        
        //case 2: last slice include first slice dropped
        vector<int> prev2(k+2, 0);
        vector<int> cur2(k+2, 0);
        vector<int> next2(k+2, 0);
        for (int index = k-1; index >= 1; index--) {
            for (int n = 1; n <= k/3; n++) {
                int eat = slices[index] + next2[n-1];
                int noteat = cur2[n];

                prev2[n] = max (eat, noteat);
            }
            next2 = cur2;
            cur2 = prev2;
        }
        int case2 = cur2[k/3];
        
        return max (case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // int case1 = solve (0, k-2, slices, k/3);
        // int case2 = solve (1, k-1, slices, k/3);
        // return max (case1, case2);
        
        // int k = slices.size();
        // vector<vector<int> > dp1(k, vector<int> (k, -1));
        // int case1 = solveMem (0, k-2, slices, k/3, dp1);
        // vector<vector<int> > dp2(k, vector<int> (k, -1));//we can't use same dp for both cases
        // int case2 = solveMem (1, k-1, slices, k/3, dp2);
        // return max (case1, case2);
        
    
        // return solveTab (slices);
        
        return solveTabSO (slices);
    }
};
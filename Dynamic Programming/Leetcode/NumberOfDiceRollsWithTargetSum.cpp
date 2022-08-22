#define MOD 1000000007
class Solution {
public:
    
    int solve (int dice, int faces, int target) {
        //base case
        if (target < 0) 
            return 0;
        if (dice == 0 && target != 0) 
            return 0;
        if (target == 0 && dice != 0)
            return 0;
        if (dice == 0 && target == 0) 
            return 1;
        
        int ans = 0;
        for (int i = 1; i <= faces; i++) {
            ans += solve (dice-1, faces, target-i);
        }
        return ans;
    }
    int solveMem (int dice, int faces, int target, vector<vector<int> >& dp) {
        //base case
        if (target < 0) 
            return 0;
        if (dice == 0 && target != 0) 
            return 0;
        if (target == 0 && dice != 0)
            return 0;
        if (dice == 0 && target == 0) 
            return 1;
        
        if (dp[dice][target] != -1)
            return dp[dice][target];
        
        int ans = 0;
        for (int i = 1; i <= faces; i++) {
            ans = ((ans)%MOD + (solveMem(dice-1, faces, target-i, dp)%MOD))%MOD;
        }
        return dp[dice][target] = ans;
    }
    int solveTab (int n, int k, int t) {
        vector<vector<int> > dp(n+1, vector<int>(t+1, 0));
        //after analysing base case
        dp[0][0] = 1;
        for (int dice = 1; dice <= n; dice++) {
            for (int target = 1; target <= t; target++) {
                
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (target - i >= 0)
                        ans = ((ans)%MOD + dp[dice-1][target-i] %MOD)%MOD;
                }
                dp[dice][target] = ans; 
            }
        }
        return dp[n][t];
    }
    int solveTabSO (int n, int k, int t) {
        vector<int> cur(t+1, 0);
        vector<int> prev(t+1, 0);
        //after analysing base case
        prev[0] = 1;
        for (int dice = 1; dice <= n; dice++) {
            for (int target = 1; target <= t; target++) {
                
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (target - i >= 0)
                        ans = ((ans)%MOD + prev[target-i] %MOD)%MOD;
                }
                cur[target] = ans; 
            }
            prev = cur;
        }
        return prev[t];
    }
    int numRollsToTarget(int n, int k, int target) {
        // return solve (n, k, target);
        
//         vector<vector<int> > dp(n+1, vector<int> (target+1, -1));
        
//         return solveMem (n, k, target, dp);
        
        // return solveTab (n, k, target);
        
            return solveTabSO (n, k, target);
    }
};
class Solution {
public:
    
    int solve (vector<int> &obstacles, int curlane, int curpos) {
        //base case
        if (curpos == obstacles.size() -1) 
            return 0;
        
        if (obstacles[curpos+1] != curlane) {
            return solve (obstacles, curlane, curpos+1);
        }
        else {
            //sideways jump
            int ans = INT_MAX;
            for (int i=1; i<=3; i++) {
                if (curlane != i && obstacles[curpos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, curpos));
            }
            return ans;
        }
    }
    int solveMem (vector<int> &obstacles, int curlane, int curpos, vector<vector<int> > &dp) {
        //base case
        if (curpos == obstacles.size() -1) 
            return 0;
        
        if ( dp[curlane][curpos] != -1) 
            return  dp[curlane][curpos];
        
        if (obstacles[curpos+1] != curlane) {
            return solveMem (obstacles, curlane, curpos+1, dp);
        }
        else {
            //sideways jump
            int ans = INT_MAX;
            for (int i=1; i<=3; i++) {
                if (curlane != i && obstacles[curpos] != i)
                    ans = min(ans, 1 + solveMem(obstacles, i, curpos, dp));
            }
            dp[curlane][curpos] = ans;
            return dp[curlane][curpos];
        }
    }
    int solveTab (vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int> > dp(3+1, vector<int> (obstacles.size(), 1e9));
        //if destination pe khadi hai kisi bhi lane me
        //toh min jumps = 0
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        //choices
        //dest se reverse origin pe jao
        for (int curpos = n-1; curpos>=0; curpos--) {
            for (int curlane = 1; curlane<=3; curlane++) {
                
                if (obstacles[curpos+1] != curlane) {
                    dp[curlane][curpos] = dp[curlane][curpos+1]; 
                }
                else {
                    //sideways jump
                    int ans = 1e9; // int max se intger overflow ho raha tha
                    for (int i=1; i<=3; i++) {
                        if (curlane != i && obstacles[curpos] != i)
                            ans = min(ans, 1 + dp[i][curpos]);
                    }
                    dp[curlane][curpos] = ans;
                }
            }
        }
        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));    
    }
    int solveTabSO (vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        
        vector<int> cur(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        //if destination pe khadi hai kisi bhi lane me
        //toh min jumps = 0
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        
        //choices
        //dest se reverse origin pe jao
        for (int curpos = n-1; curpos>=0; curpos--) {
            for (int curlane = 1; curlane<=3; curlane++) {
                
                if (obstacles[curpos+1] != curlane) {
                    cur[curlane] = next[curlane]; 
                }
                else {
                    //sideways jump
                    int ans = 1e9;
                    for (int i=1; i<=3; i++) {
                        if (curlane != i && obstacles[curpos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                    cur[curlane] = ans;
                }
            }
            next = cur;
        }
        return min(next[2], min(next[1]+1, next[3]+1));
        
    }
    
    int minSideJumps(vector<int>& obstacles) {
        // return solve (obstacles, 2, 0);
        
        // vector<vector<int> > dp(4, vector<int> (obstacles.size(), -1));
        // return solveMem (obstacles, 2, 0, dp);
        
        // return solveTab (obstacles);
        
        return solveTabSO (obstacles);
    }
};
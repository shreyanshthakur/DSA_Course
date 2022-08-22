class Solution {
public:
    bool solve (int index, vector<int>& nums, int n, int target) {
        //base case
        if (index >= n || target < 0)
            return 0;
        if (target == 0)
            return 1;
        
        bool inc = solve (index+1, nums, n, target-nums[index]);
        bool exc = solve (index+1, nums, n, target);
        
        return (inc or exc);
    }
    bool solveMem (int index, vector<int>& nums, int n, int target, vector<vector<int> >& dp) {
        //base case
        if (index >= n || target < 0)
            return 0;
        if (target == 0)
            return 1;
        
        if (dp[index][target] != -1)
            return dp[index][target];
        
        bool inc = solveMem (index+1, nums, n, target-nums[index], dp);
        bool exc = solveMem (index+1, nums, n, target, dp);
        
        return dp[index][target] = (inc or exc);
    }
    bool solveTab (vector<int>& nums, int n, int t) {
        vector<vector<int> > dp(n+1, vector<int>(t+1, 0));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= t; target++) {
                
                bool inc = 0;
                if (target - nums[index] >= 0)
                    inc = dp[index+1][target - nums[index]];
                bool exc = dp[index+1][target];
                
                dp[index][target] = inc or exc;
            }
        }
        return dp[0][t];
    }
    bool solveTabSO (vector<int>& nums, int n, int t) {
        vector<int> cur(t+1, 0);
        vector<int> next(t+1, 0);
        
        cur[0] = 1;
        next[0] = 1;
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= t; target++) {
                
                bool inc = 0;
                if (target - nums[index] >= 0)
                    inc = next[target - nums[index]];
                bool exc = next[target];
                
                cur[target] = inc or exc;
            }
            next = cur;
        }
        return next[t];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //calculate array sum
        int sum = 0;
        for (int i = 0; i < n; i++) 
            sum += nums[i];
        
        if (sum & 1) 
            return 0;
        int target = sum/2;
        // return solve(0, nums, n, target);
        
        // vector<vector<int> > dp(n, vector<int>(target+1, -1));
        // return solveMem (0, nums, n, target, dp);
        
        // return solveTab (nums, n, target);
        
        return solveTabSO (nums, n, target);
    }
};
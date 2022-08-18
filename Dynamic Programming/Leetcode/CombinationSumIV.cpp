class Solution {
public:
    
    int solve (vector<int>& nums, int target, int n) {
        
        //base case
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        
        //recursive calls + processing
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solve (nums, target-nums[i], n);
        }
        return ans;
    }
    
    int solveMem (vector<int>& nums, int target, int n, vector<int> &dp) {
        
        //base case
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        
        //don't calculate if already calculated
        if (dp[target] != -1) 
            return dp[target];
        
        
        //recursive calls + processing
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solveMem (nums, target-nums[i], n, dp);
        }
        
        dp[target] = ans;
        return dp[target];
    }
    
    int solveTab (vector<int>& nums, int target, int n) {
        
        //step 1: dp array create
        vector<int> dp(target+1, 0);
        
        //step 2: initialise some dp elements by base case analyse
        dp[0] = 1;
        
        //step 3: loop for rest of the space
        //traversing from bottom (viz 1) to target
        for (int i = 1; i <= target; i++) {
            //traversing on choices e.g. {1, 2, 5}
            for (int j = 0; j < n; j++) {
                if (i - nums[j] >= 0 && (dp[i] + dp[i-nums[j]]) <= INT_MAX ) 
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        // int n = nums.size();
        // return solve (nums, target, n);
        
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return solveMem (nums, target, n, dp);
        
        // int n = nums.size();
        // return solveTab (nums, target, n);
    }
};
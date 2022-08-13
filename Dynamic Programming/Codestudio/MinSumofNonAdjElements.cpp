int solve (vector<int> &nums, int n) {
    //base case
    if (n < 0)
        return 0;
    if (n == 0) 
        return nums[0];
    
    int incl = solve (nums, n-2) + nums[n];
    int excl = solve (nums, n-1) + 0;
    
    return max(incl, excl);
}

int solveMem (vector<int> &nums, int n, vector<int> &dp) {
    //base case
    if (n < 0)
        return 0;
    if (n == 0) 
        return nums[0];
    
    if (dp[n] != -1)
        return dp[n];
    
    int incl = solveMem (nums, n-2, dp) + nums[n];
    int excl = solveMem (nums, n-1, dp) + 0;
    
    dp[n] = max(incl, excl);
    return dp[n];
}

int solveTab (vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);// initialse every sum to 0
    
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}

int solveSO (vector<int> &nums) {
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];
    
    for (int i = 1; i < n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        
        int ans = max(incl, excl);
        //shift
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     int ans = solve (nums, n-1);//solving reverse i.e. right to left 
//     return ans;
    
//     int n = nums.size();
//     vector<int> dp(n, -1);// n bcz array di hai
//     return solveMem (nums, n-1, dp);
    
    return solveSO (nums);
    
    
}
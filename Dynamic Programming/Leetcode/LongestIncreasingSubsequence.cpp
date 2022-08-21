class Solution {
public:
    
    int solve (vector<int>& nums, int cur, int prev) {
        //base case
        if (cur == nums.size()) 
            return 0;
        
        int include = 0;
        if (prev == -1 || nums[prev] < nums[cur]) {
            include = 1 + solve (nums, cur+1, cur);//prev index cur index bangaya cur index aage badh gaya  
        }
        int exclude = solve (nums, cur+1, prev);
            
        return max (include, exclude);
    }
    int solveMem (int n, vector<int>& nums, int cur, int prev, vector<vector<int> > &dp) {
        //base case
        if (cur == n) 
            return 0;
        
        if (dp[cur][prev+1] != -1) 
            return dp[cur][prev+1];
        
        int include = 0;
        if (prev == -1 || nums[prev] < nums[cur]) {
            include = 1 + solveMem (n, nums, cur+1, cur, dp);//prev index cur index bangaya cur index aage badh gaya  
        }
        int exclude = solveMem (n, nums, cur+1, prev, dp);
            
        //yaha prev+1 kyuki -1 index se initialize kiya hai, and taaki valid index rahe
        return dp[cur][prev+1] = max (include, exclude);
    }
    int solveTab (int n, vector<int>& nums) {
        vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
        
        //no initialise coz already ini from 0
        for (int cur = n-1; cur>=0; cur--) {
            for (int prev = cur-1; prev>=-1; prev--) {
                
                int include = 0;
                if (prev == -1 || nums[prev] < nums[cur]) {
                    include = 1 + dp[cur+1][cur+1];
                }
                int exclude = dp[cur+1][prev+1];
                dp[cur][prev+1] = max (include, exclude);
            }
        }
        return dp[0][-1+1];
    }
    int solveTabSO (int n, vector<int>& nums) {
        
        vector<int> curRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for (int cur = n-1; cur>=0; cur--) {
            for (int prev = cur-1; prev>=-1; prev--) {
                
                int include = 0;
                if (prev == -1 || nums[prev] < nums[cur]) {
                    include = 1 + nextRow[cur+1];
                }
                int exclude = nextRow[prev+1];
                curRow[prev+1] = max (include, exclude);
            }
            nextRow = curRow;
        }
        return nextRow[-1+1];
    }
    int solveOptimal (int n, vector<int>& nums) {
        if (n == 0) 
            return 0;
        
        vector<int> ans;
        ans.push_back(nums[0]);//pehla element push
        
        //baki ke liye loop
        for (int i=1; i<n; i++) {
            if (nums[i] > ans.back())
                ans.push_back(nums[i]);
            else {
                //find index of jussst bada element in ans
                //lower bound func uses binary search toh TC O(logn)
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // return solve (nums, 0, -1);
        
        // int n = nums.size();
        // vector<vector<int> > dp(n, vector<int> (n+1, -1));
        // return solveMem (n, nums, 0, -1, dp);
        
        // int n = nums.size();
        // return solveTab (n, nums);
        
        // int n = nums.size();
        // return solveTabSO (n, nums);
        
        int n = nums.size();
        return solveOptimal (n, nums);
    }
};
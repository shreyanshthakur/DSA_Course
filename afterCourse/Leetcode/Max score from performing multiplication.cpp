class Solution {
public:
    int solve (vector<int>& nums, vector<int>& mult, int s, int index, vector<vector<int> >& dp, int n) {
        //base case 
        if (index == mult.size()) 
            return 0;
        
        if (dp[s][index] != INT_MIN)
            return dp[s][index];
        
        int start = nums[s] * mult[index] + solve (nums, mult, s+1, index+1, dp, n);
        
        int end =  nums[(n-1)-(index-s)] * mult[index] + solve (nums, mult, s, index+1, dp, n);
        
        return dp[s][index] = max (start, end);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int> > dp(m+1, vector<int>(m+1, INT_MIN));
        
        return solve (nums, multipliers, 0, 0, dp, n);
    }
};
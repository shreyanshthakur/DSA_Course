class Solution {
public:
    
    int solve (vector<int>& satisfaction, int index, int time) {
        //base case
        if (index == satisfaction.size()) 
            return 0;
        
        int include = (time+1) * satisfaction[index] + solve (satisfaction, index+1, time+1);
        int exclude = solve (satisfaction, index+1, time);
        
        return max(include, exclude);
    }
    int solveMem (vector<int>& satisfaction, int index, int time, vector<vector<int> > &dp) {
        //base case
        if (index == satisfaction.size()) 
            return 0;
        
        if (dp[index][time] != -1) 
            return dp[index][time];
        
        int include = (time+1) * satisfaction[index] + solveMem (satisfaction, index+1, time+1, dp);
        int exclude = solveMem (satisfaction, index+1, time, dp);
        
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    int solveTab (vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
        
        for (int index = n-1; index>=0; index--) {
            for (int time = index; time>=0; time--) {
                int include = (time+1) * satisfaction[index] + dp[index+1][time+1];
                int exclude = dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveTabSO (vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        
        vector<int> cur(n+1, 0);
        vector<int> next(n+1, 0);
        
        for (int index = n-1; index>=0; index--) {
            for (int time = index; time>=0; time--) {
                int include = (time+1) * satisfaction[index] + next[time+1];
                int exclude = next[time];

                cur[time] = max(include, exclude);
            }
            next = cur;
        }
        return next[0];
    }
    int solveGreedy (vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            int sum = 0;
            int time = 0;
            for (int j = i; j < satisfaction.size(); j++) {
                sum += (++time) * satisfaction[j];
            }
            ans = max (ans, sum);
        }
        return ans;
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        // //sort karlo
        // sort(satisfaction.begin(), satisfaction.end());
        // return solve (satisfaction, 0, 0);
        
        
        // sort(satisfaction.begin(), satisfaction.end());
        // int n = satisfaction.size();
        // vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
        // return solveMem (satisfaction, 0, 0, dp);
        
        // sort(satisfaction.begin(), satisfaction.end());
        // return solveTab (satisfaction);
        
        // sort(satisfaction.begin(), satisfaction.end());
        // return solveTabSO (satisfaction);
        
        return solveGreedy (satisfaction);
    }
};
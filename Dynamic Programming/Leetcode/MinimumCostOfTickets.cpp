class Solution {
public:
    
    int solve (vector<int>& days, vector<int>& costs, int index, int n) {
        
        //base case 
        if (index >= n) {
            return 0;
        }
        
        //options
        
        //one day pass
        int oneDayPass = costs[0] + solve (days, costs, index + 1, n);
        
        //seven day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        
        int sevDayPass = costs[1] + solve (days, costs, i, n);
        
        //thirty day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        int ttyDayPass = costs[2] + solve (days, costs, i, n);
        
        return min(oneDayPass, min(sevDayPass, ttyDayPass) );
    }
    
    int solveMem (vector<int>& days, vector<int>& costs, int index, int n, vector<int> dp) {
        
        //base case 
        if (index >= n) {
            return 0;
        }
        
        if (dp[index] != -1)
            return dp[index];
        
        //options
        
        //one day pass
        int oneDayPass = costs[0] + solveMem (days, costs, index + 1, n, dp);
        
        //seven day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        
        int sevDayPass = costs[1] + solveMem (days, costs, i, n, dp);
        
        //thirty day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        int ttyDayPass = costs[2] + solveMem (days, costs, i, n, dp);
        
        dp[index] = min(oneDayPass, min(sevDayPass, ttyDayPass));
        return dp[index];
    }
    
    int solveTab (vector<int>& days, vector<int>& costs, int n) {
        //step 1: create dp array
        vector<int> dp(n+1, INT_MAX);
        //step 2: initialise dp array by analysing base cases
        dp[n] = 0;
        //step 3: loop over rest to find rest of dp array value
        for (int k = n-1; k >= 0; k--) {
            //options
        
            //one day pass
            int oneDayPass = costs[0] + dp[k + 1];

            //seven day pass
            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++);

            int sevDayPass = costs[1] + dp[i];

            //thirty day pass
            for (i = k; i < n && days[i] < days[k] + 30; i++);
            int ttyDayPass = costs[2] + dp[i];
            dp[k] = min(oneDayPass, min(sevDayPass, ttyDayPass));
        }
        
        return dp[0];
        
    }

    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // return solve (days, costs, 0, n);
        
        // int n = days.size();
        // vector<int> dp(n+1, -1);
        // return solveMem (days, costs, 0, n, dp);
        
        int n = days.size();
        return solveTab (days, costs, n);
        
        
};
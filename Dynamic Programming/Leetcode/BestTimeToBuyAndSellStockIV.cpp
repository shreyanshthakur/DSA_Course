int solveTabSO (vector<int>& prices) {
        int n = prices.size();

        vector<vector<int> > cur(2, vector<int>(3, 0));
        vector<vector<int> > next(2, vector<int>(3, 0));
        
        
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) { //limit = 0 base case tha so no need to consider
                    int profit = 0;
                    if (buy) {
                        profit = max ( -prices[index] + next[0][limit], 0 + next[1][limit] );    
                    }
                    else {
                        profit = max ( +prices[index] + next[1][limit-1], next[0][limit] );
                    }
                    cur[buy][limit] = profit;
                }
                next = cur;
            }
        }
        return next[1][2];
    }
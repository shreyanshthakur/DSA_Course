class Solution {
public://Bottom-Up Approach (space optimisation)
    int fib(int n) {
        //step 1: Create a dp array
        //vector<int> dp(n+1);
        //step 2: Initialise by analysing base cases
        int prev1 = 1;
        
        int prev2 = 0;
        if (n == 0) 
            return prev2;
        //step 3: Apply for loop by analysing work range
        for (int i = 2; i <= n; i++) {
            int cur = prev1 + prev2;
            //shift
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
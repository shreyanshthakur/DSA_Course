//space optimised
class Solution {
public:
    
    int solve (vector<int> &cost, int n) {
        //starting 2 seedhiyo ka calculate karlo
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        //2 seedhiyo ke bad se n-1 tak loop
        for (int i = 2; i < n; i++) {
            //iss cur seedhi pe aye usme mincost itni lagii
            int cur = cost[i] + min(prev1, prev2);
            //shift kardo
            prev2 = prev1;
            prev1 = cur;
        }
        //return minimum way
        return min(prev1, prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};
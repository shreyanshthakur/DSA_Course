#define mod 1000000007
class Solution {
public:
    
    long long solve (int n, vector<int>& speed, vector<int>& eff, int k, 
              int miniEff, int prevSpeed, int index) {
        //base case
        if (k <= 0 || index == n)
            return (prevSpeed%mod * miniEff%mod)%mod;
        
        long long include = solve (n, speed, eff, k-1, min(miniEff, eff[index]), (prevSpeed%mod + speed[index]%mod)%mod, index+1)%mod;
        long long exclude =  solve (n, speed, eff, k, miniEff, prevSpeed%mod, index+1)%mod; 
        
        return max (include, exclude);
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // vector<vector<vector<vector<int> > > > dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1))));
        return solve (n, speed, efficiency, k, INT_MAX, 0, 0)%mod;
    }
};
class Solution {
public:
    int solve (string &s, int i, vector<int>& dp) {
        //base case
        if (i == s.length())
            return 1;
        if (s[i] == '0')
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        string temp = s.substr(i, 2);
        int oneD = solve (s, i+1, dp);
        int twoD = 0;
        if( i < s.length()-1 && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7'))) {
            twoD = solve (s, i+2, dp);
        }
        return dp[i] = oneD+twoD;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        return solve (s, 0, dp);
    }
};
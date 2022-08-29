class Solution {
public:
    int solveTabSO (string a, string b) {
        vector<int> cur(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);
        
        for (int i = a.length()-1; i >= 0; i--) {
            for (int j = b.length()-1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + next[j+1];
                }
                else {
                    ans = max (next[j], cur[j+1]);
                }
                cur[j] = ans;
            }
            next = cur;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string revstr = s;
        reverse (revstr.begin(), revstr.end());
        int ans = solveTabSO (s, revstr);
        return ans;
    }
};
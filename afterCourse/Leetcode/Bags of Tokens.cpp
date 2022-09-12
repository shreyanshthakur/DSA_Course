class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort (tokens.begin(), tokens.end());
        int ans = 0;
        int score = 0;
        int i = 0, j = tokens.size()-1;
        while (i <= j) {
            
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
                ans = max (ans, score);
            }
            
            else if (score >= 1) {
                score--;
                power += tokens[j];
                j--;
            }  
            else {
                break;
            }
        }
        return ans;
    }
};
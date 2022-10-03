class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, maxtime = 0, sumtime = 0;
        for (int i = 0; i < neededTime.size(); i++) {
            if (i > 0 && colors[i] != colors[i-1]) {
                ans += sumtime - maxtime;
                sumtime = 0;
                maxtime = 0;
            }
            maxtime = max (neededTime[i], maxtime);
            sumtime += neededTime[i];
        }
        ans += sumtime - maxtime;
        return ans;
    }
};
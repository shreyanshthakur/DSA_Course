class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int i = 0; i < grid[0].size(); i++) {
            int src = i, dest;
            for (int j = 0; j < grid.size(); j++) {
                dest = src + grid[j][src];
                if (dest < 0 || dest >= grid[0].size() || grid[j][src] != grid[j][dest]) {
                    src = -1;
                    break;
                }
                src = dest;
            }
            ans.push_back (src);
        }
        return ans;
    }
};
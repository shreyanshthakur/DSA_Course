class Solution {
public:
    bool isSafe (int newx, int newy, vector<vector<int>>& grid, int m, int n) {
        if ((newx >= 0) && (newx < m) && (newy >= 0) && (newy < n) && grid[newx][newy] == 1) return true;
        else return false;
    }
        
    int solve (int i, int j, vector<vector<int>>& grid, int m, int n) {
        if (isSafe(i, j, grid, m, n)) {
            grid[i][j] = -1;
            
            int left = solve (i, j-1, grid, m, n);
            int right = solve (i, j+1, grid, m, n);
            int up = solve (i-1, j, grid, m, n);
            int down = solve (i+1, j, grid, m, n);
            
            return 1 + left + right + up + down;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        //step1 : two for loop lagado
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //place the player when loop 1st encounters 1 in matrix
                if (grid[i][j] == 1) {
                    maxi = max (maxi , solve (i, j, grid, m, n));
                }
            }
        }
        return maxi;
    }
};
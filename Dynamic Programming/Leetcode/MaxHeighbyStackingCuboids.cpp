class Solution {
public:
    
    bool check (vector<int> base, vector<int> newBox) {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]) 
            return true;
        else 
            return false;
    }
    
    int solveTabSO (int n, vector<vector<int>>& nums) {
        
        vector<int> curRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for (int cur = n-1; cur>=0; cur--) {
            for (int prev = cur-1; prev>=-1; prev--) {
                
                int include = 0;
                if (prev == -1 || check(nums[cur], nums[prev])) {
                    include = nums[cur][2] + nextRow[cur+1];
                }
                int exclude = nextRow[prev+1];
                curRow[prev+1] = max (include, exclude);
            }
            nextRow = curRow;
        }
        return nextRow[-1+1];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1: sort the dimension inside each cuboid
        for (auto &a : cuboids)
            sort(a.begin(), a.end());
        
        //step 2: sort cuboids aapas mein
        sort(cuboids.begin(), cuboids.end());
        
        //step 3: apply LIS logic
        return solveTabSO (cuboids.size(), cuboids);
        
    }
};
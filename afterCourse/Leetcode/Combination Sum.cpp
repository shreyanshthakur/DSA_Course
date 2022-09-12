class Solution {
public:
    
    void solve (const vector<int>& candidates, int target, int sum, vector<int>& temp, vector<vector<int>>& ans, int index) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            //recursive call
            solve (candidates, target, sum, temp, ans, i);
            //backtrack
            temp.pop_back();
            sum -= candidates[i];
        } 
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int> > ans;
        solve (candidates, target, 0, temp, ans, 0);
        return ans;
    }
};
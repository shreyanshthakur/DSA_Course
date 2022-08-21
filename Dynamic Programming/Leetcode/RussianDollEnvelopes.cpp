class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int solveOptimal (int n, vector<vector<int>>& envelopes) {
        if (n == 0) 
            return 0;
        
        vector<int> ans;
        ans.push_back(envelopes[0][1]);//pehla element push
        
        //baki ke liye loop
        for (int i=1; i<n; i++) {
            if (envelopes[i][1] > ans.back())
                ans.push_back(envelopes[i][1]);
            else {
                //find index of jussst bada element in ans
                //lower bound func uses binary search toh TC O(logn)
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        //step 1: sort ascending order and 
        sort (envelopes.begin(), envelopes.end(), cmp);
        return solveOptimal (n, envelopes);
    }
};
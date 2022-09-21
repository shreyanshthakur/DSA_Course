class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int evenSum = 0;
        for (auto i : nums) {
            if (i%2==0) evenSum += i;
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            //pehle ka ith element
            if (nums[index]%2 == 0)
                evenSum -= nums[index];// sum mese vo number minus
            nums[index] += val;
            if (nums[index]%2 == 0)
                evenSum += nums[index];
            ans.push_back(evenSum);
        }
        return ans;
    }
};
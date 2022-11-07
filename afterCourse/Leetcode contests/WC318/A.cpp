class Solution {
public:
    void util (vector<int>& nums, int &n) {
        for (int i = 0; i < n;) {
            while (i+1 < n && nums[i] != 0) i++;
            int j = i+1;
            while (j+1 < n && nums[j] == 0) j++;
            if (i < n && j < n)
                swap (nums[i], nums[j]);
            i++;
        }
    }
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        util (nums, n);
        return nums;
    }
};
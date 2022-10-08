class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> m;
        for (auto &i : nums1) 
            for (auto &j : nums2) 
                m[i+j]++;
        for (auto &i : nums3)
            for (auto &j : nums4)
                if (m.count(0-(i+j))) count += m[0-(i+j)];
        return count;
    }
};
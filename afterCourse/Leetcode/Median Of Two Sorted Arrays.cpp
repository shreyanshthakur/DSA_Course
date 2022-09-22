class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> v;
        for (auto i : nums1) v.push_back(i);
        for (auto i : nums2) v.push_back(i);
        sort(v.begin(), v.end());
        
        int x = v.size();
        if (x%2 == 0) {
            return (v[(x/2)-1] + v[x/2])/2.00000;
        }
        else {
            return v[x/2];
        }
    }
};
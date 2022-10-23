
class Solution {
public:
    using ll = long long;
    ll solve (ll m, vector<int>& nums, vector<int>& cost) {
        ll curcost = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            curcost += (ll)(cost[i] * abs(nums[i] - m));
        }
        return curcost;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l = *min_element (nums.begin(), nums.end());
        ll h = *max_element (nums.begin(), nums.end());
        while (l < h) {
            ll mid = (l+h)/2;
            ll a = solve (mid, nums, cost);
            ll b = solve (mid+1, nums, cost);
            if (a > b) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        return solve (l, nums, cost);
    }
};
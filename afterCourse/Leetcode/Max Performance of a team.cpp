#define mod 1000000007
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {efficiency[i], speed[i]};
        }
        sort(v.rbegin(), v.rend());
        long speedSum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (auto& [e, s] : v) {
            pq.push(s);
            speedSum += s;
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            ans = max (ans, speedSum * e);
        }
        return ans%mod;
    }
};
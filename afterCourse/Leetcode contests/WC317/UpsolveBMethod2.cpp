class Solution {
public:
    struct video {
        long long sum = 0;
        string small;
        int max_view = 0;
    };
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        unordered_map<string, video> m;
        long long count = 0;
        for (int i = 0; i < c.size(); i++) {
            if (!m.count(c[i])) {
                m[c[i]] = {views[i], ids[i], views[i]};
                count = max (count, m[c[i]].sum);
                continue;
            }
            m[c[i]].sum += views[i];
            if (m[c[i]].max_view < views[i] || m[c[i]].max_view == views[i] && m[c[i]].small > ids[i]) {
                m[c[i]].max_view = views[i];
                m[c[i]].small = ids[i];
            }
            count = max (count, m[c[i]].sum);
        }
        vector<vector<string> > ans;
        for (auto &i : m) {
            if (i.second.sum == count) {
                ans.push_back({i.first, i.second.small});
            }
        }
        return ans;
    }
};
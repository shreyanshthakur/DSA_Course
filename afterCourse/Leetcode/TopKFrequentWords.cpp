class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto &s : words) m[s]++;
        auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > pq (comp);
        for (auto &i : m) {
            pq.push({i.first, i.second});
            if (pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.insert(ans.begin(), pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
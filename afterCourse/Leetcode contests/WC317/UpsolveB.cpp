class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string> > ans;
        unordered_map<string, long long> creator_to_maxViews;
        unordered_map<string, string> creator_to_video;
        unordered_map<string, int> creator_to_views;
        
        int n = creators.size();
        
        for (int i = 0; i < n; i++) {
            creator_to_maxViews[creators[i]] += views[i];
            
            //check if creator name present in creator_to_video map
            if (creator_to_video.find(creators[i]) == creator_to_video.end()) {//creator entry not found
                creator_to_video[creators[i]] = ids[i];
                creator_to_views[creators[i]] = views[i];
            }
            else {//creator entry present
                if (creator_to_views[creators[i]] == views[i]) {
                    creator_to_video[creators[i]] = min (creator_to_video[creators[i]], ids[i]); //store lexicographically smaller video id
                }
                else if (creator_to_views[creators[i]] < views[i]) {
                    creator_to_video[creators[i]] = ids[i];
                    creator_to_views[creators[i]] = views[i];
                }
            }
        }
        
        priority_queue<pair<int, string> > pq;
        for (auto &i : creator_to_maxViews) pq.push({i.second, i.first});
        
        int maxi = pq.top().first;
        
        while (!pq.empty() && pq.top().first == maxi) {
            vector<string> v;
            string s = pq.top().second;
            pq.pop();
            v.push_back(s);
            v.push_back(creator_to_video[s]);
            ans.push_back(v);
        }
        return ans;
        
    }
};
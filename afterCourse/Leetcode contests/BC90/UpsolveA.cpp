class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, int> m1;
        unordered_map<string, string> m2;
        for (auto &w : words) {
            string s = "";
            for (int i = 0; i < w.size()-1; i++) {
                int t = w[i+1] - w[i];
                s += to_string(t) + "$";
            }
            m1[s]++;
            m2[s] = w;
        }
        for (auto &i : m1) {
            if (i.second == 1) return m2[i.first];
        }
        return "";
    }
};
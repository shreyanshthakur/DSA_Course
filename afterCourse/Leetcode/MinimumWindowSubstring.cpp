class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto &c : t) m[c]++;
        int start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        int size = s.size();
        while (end < size) {
            if (m[s[end]] > 0) {
                counter--;
            }
            m[s[end]]--;
            end++;
            while (counter == 0) {
                //update start index and minLen
                if (end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                }
                m[s[start]]++;//jis index se aage gaye ab us character ko bhi dhundhna hai aage ki string mein
                if (m[s[start]] > 0) {
                    counter++;
                }
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
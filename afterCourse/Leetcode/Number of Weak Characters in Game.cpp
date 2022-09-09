class Solution {
public:
    
    static bool cmp (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        // for (int i = 0; i < properties.size(); i++) {
        //     cout << '(' << properties[i][0]<<','<<properties[i][1]<<')'<<',';
        // }cout << endl;
        int maxi = INT_MIN;
        int count = 0;
        for (int i = properties.size()-1; i >= 0; i--) {
            if (properties[i][1] < maxi) {
                count++;
            }           
            maxi = max(properties[i][1], maxi);
        }
        return count;
    }
};
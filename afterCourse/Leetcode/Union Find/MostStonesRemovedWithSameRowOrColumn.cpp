class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            uni (stones[i][0], ~stones[i][1]);
        }
        return stones.size() - islands;
    }
    
    unordered_map<int, int> m;
    int islands = 0;
    
    int find (int x) {
        if (!m.count(x)) {
            m[x] = x;
            islands++;
        } 
        if (x != m[x]) 
            m[x] = find(m[x]);
        return m[x];
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            m[x] = y;
            islands--;
        }
    }
};
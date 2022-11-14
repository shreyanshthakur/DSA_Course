/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minOpsUtil (vector<int>& v) {
        vector<pair<int, int>> u;
        for (int i = 0; i < v.size(); i++) {
            u.push_back({v[i], i});
        }
        sort (u.begin(), u.end());
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (u[i].second == i) continue;
            else {
                cnt++;
                swap (u[i], u[u[i].second]);
                i--;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ans = 0;
        vector<int> v;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL) {
                ans += minOpsUtil (v);
                v.clear();
                //cout << endl;//debug
                if (!q.empty()) q.push(NULL);
            }
            else {
                //cout << front->val << " ";//debug
                v.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);    
            }
            
        }
        return ans;
    }
};
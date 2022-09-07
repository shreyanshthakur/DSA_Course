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
    void solve (TreeNode* root, string& s) {
        if (root == NULL) 
            return;
        
        s += to_string(root->val);
        
        if (root->left) {
            s.push_back('(');
            solve (root->left, s);
            s.push_back(')');
        }
        if (root->left == NULL && root->right != NULL) {
            s += "()";
        }
        if (root->right) {
            s.push_back('(');
            solve (root->right, s);
            s.push_back(')');
        }
        return;
            
    }
    string tree2str(TreeNode* root) {
        string ans;
        solve (root, ans);
        return ans;
    }
};
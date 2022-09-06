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
    TreeNode* solve (TreeNode* root) {
        //base case
        if (root == NULL) {
            return NULL;
        }
        
        //recursive calls
        root->left = solve (root->left);
        root->right = solve (root->right);
        
        //processing
        if (root->left == NULL && root->right == NULL && root->val == 0) {
            root = NULL;
        }
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);
    }
};
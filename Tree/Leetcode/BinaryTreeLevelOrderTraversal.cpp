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
    
    void levelOrderTraversal(TreeNode* root,vector<vector<int>> &ans, vector<int> &v) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {//purana level complete traverse ho chuka hai
                ans.push_back(v);
                v = {};
                if (!q.empty()) {
                    //queue still has some child nodes
                    q.push(NULL);
                }  
            }
            else {
                v.push_back(temp->val);
                //cout << temp -> data << " ";
                if (temp->left) {
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans = {};
        vector<int> v;
        if (root==NULL) return ans;
        levelOrderTraversal(root, ans, v);
        return ans;
        
    }
};
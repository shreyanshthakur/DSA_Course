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
    
    vector<double> levelOrderTraversal (TreeNode* root, vector<double>& ans) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        int count = 0;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp != NULL) {
                
                v.push_back(temp->val);
                count++;
                //cout << temp->val << " "; //debug
                
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else {
                long long int sum = 0;
                int n = v.size();
                for (int i = n-1; i >= 0 ; i--) {
                    sum += v[i];
                    //cout<<v[i]<<" ";
                    v.pop_back();
                }
                //cout << endl;
                double avg = (1.00000 * sum) / count;
                //cout <<"count = "<< count << " " << endl;//debug
                count = 0;
                //cout <<"Sum = "<< sum << " " << endl;//debug
                ans.push_back(avg);
                vector<int> v;
                //cout << endl;//debug
                if (!q.empty())
                    q.push(NULL);
            }
        }
        return ans;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        levelOrderTraversal(root, ans);
        
        return ans;
    }
};
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //create a map which will store all the node values 
        //present at that particular horizontal distance(hd) and level(lvl)
        map <int, map <int, multiset<int> > > m;//(hd, level, array)
        //create a queue which will store node pointer and corresponding
        //values of hd and lvl
        queue < pair <TreeNode*, pair<int, int> > > q;//(node, hd, lvl)
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        q.push(make_pair(root, make_pair(0,0)));

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            //push node's value into that hd, lvl
            m[hd][lvl].insert(frontNode->val);
            
            //call for rest of the tree
            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            if (frontNode->right)
                 q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for (auto i : m) {
            vector<int> a;
            for (auto j : i.second) {
                a.insert(a.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(a);
        }
        return ans;
        
    }
};
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
    bool checkPseudoPalindrome (map<int, int>& m,int& pathLen) {
        int countOdd = 0;
        for (int i = 1; i <= 9; i++) {
            if (m[i]&1) countOdd++;
        }
        if (((pathLen&1) == 0) && countOdd != 0) return false;
        if (((pathLen&1) == 1) && countOdd > 1) return false;
        return true;
    }
    int solve (TreeNode* root, map<int, int>& m, int pathLen, int& ans) {
        if (root == NULL) {
            return 0;
        }
        
        m[root->val]++;
        pathLen++;
        
        int left = solve(root->left, m, pathLen, ans);

        int right = solve(root->right, m, pathLen, ans);
                
        if (left == 0 && right == 0) {
            //check for palindrome
            if (checkPseudoPalindrome(m, pathLen)) ans++;
            //backtrack  
        }
        m[root->val]--;
        pathLen--;
        return 1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> m;
        int ans = 0;
        solve (root, m, 0, ans);
        return ans;
    }
};
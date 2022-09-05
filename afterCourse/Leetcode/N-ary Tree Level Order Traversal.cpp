/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ans;
        if (root == NULL) 
            return ans;
        queue<pair<int, Node*> > q;
        q.push({0, root});
        map <int, vector<int> > m;
        
        while (!q.empty()) {
            pair<int, Node*> temp = q.front();
            q.pop();
            Node* front = temp.second;
            int lvl = temp.first;

            m[lvl].push_back(front->val);
            
            //iterate over all the children of that node
            for (int i = 0; i < front->children.size(); i++) {
                if (front->children[i] != NULL) 
                    q.push({lvl+1, front->children[i]});
            }
        }
        for (auto i : m) {
            vector<int> a;
            for (auto j : i.second) {
                a.push_back(j);
            }
            ans.push_back(a);
        }
        return ans;
    }
};
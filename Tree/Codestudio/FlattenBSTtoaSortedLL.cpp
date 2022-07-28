/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder (TreeNode<int>* root, vector<int> &in) {
    //base case
    if (root == NULL) 
        return ;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderVal;
    //store inorder sorted values
    inorder(root, inorderVal);
    
    TreeNode<int>* newRoot = new TreeNode<int>(
    inorderVal[0]);
    TreeNode<int>* cur = newRoot;
    
    for(int i = 1; i< inorderVal.size(); i++) {
        TreeNode<int> *temp = new TreeNode<int>(
        inorderVal[i]);
        
        cur->left = NULL;
        cur->right = temp;
        cur = temp;
    }
    
    //3rd step
    cur->left = NULL;
    cur->right = NULL;
    
    return newRoot;
}

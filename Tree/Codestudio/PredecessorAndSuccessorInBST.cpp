/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //find key
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int suc = -1;
    while (temp->data != key) {
        
        if (temp->data > key) {
            suc = temp->data;//left me jane se pehle isko sotre kara lo 
            //ye potential predecessor hai
            temp = temp->left;
        }
        else {
            pred = temp->data;
            temp = temp->right;
        }
    }
    
    //pred and succ
    
    //pred
    BinaryTreeNode<int>* leftTree = temp->left;
    //ek left jake right jaate jao (maxVal vala concept)
    while (leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    //succ
    BinaryTreeNode<int>* rightTree = temp->right;
    while (rightTree != NULL) {
        suc = rightTree->data;
        rightTree = rightTree->right;
    }
    
    pair<int, int> ans = make_pair(pred, suc);
    return ans;
}

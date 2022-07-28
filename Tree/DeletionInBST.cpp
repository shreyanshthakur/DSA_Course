#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }
    cout << "Enter data for insertig in left of " << data << endl;
    root->left = buildTree(root);
    cout << "Enter data for insertig in right of " << data << endl;
    root->right = buildTree(root);
    return root;
}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL) {//purana level complete taverse ho chuka hai
            cout << endl;
            if (!q.empty()) {
                //queue still has some child nodes
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

Node* deleteFromBST( Node* root, int val) {
    //base case 
    if (root == NULL) {
        rturn root;
    }
    if (root->data == val) {
        //0 child
        if (root->left == NULL && 
        root -> right == NULL) {
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if (root->left != NULL &&
        root -> right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if (root->left == NULL &&
        root -> right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if (root->left != NULL && 
        root->right != NULL) {
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if (root->data > val) {
        root -> left = deleteFromBST(
            root->left, val)
            return root;
        
    }
    else {//right part me jao
        root->right = deleteFromBST(
            root->right, val);
            return root;
        )
    }
}

int main() {
    node* root = NULL;
    //creating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    cout << "Printing the level order traversal output" << endl;
    levelOrderTraversal(root);
    return 0;
}
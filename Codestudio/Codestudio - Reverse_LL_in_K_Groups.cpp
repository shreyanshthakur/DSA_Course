/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if (head == NULL) {
        return NULL;
    }
    
    //step1: reversef iirst k nodes
    Node* fwd = NULL;
    Node* cur = head;
    Node* prev = NULL;
    int count = 0;
    while(cur != NULL && count < k){
        fwd = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = fwd;
        count++;
    }
    
    //step 2 : recruion dekhlega
    if (fwd != NULL) {
        head -> next = kReverse(fwd, k);
    }
    //step 3: reutrn head of reversed LL
    return prev;
}
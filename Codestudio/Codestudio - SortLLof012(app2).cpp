/********************************
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

********************************/

void insertAtTail (Node* &tail, Node* cur) {
    tail -> next = cur;
    tail = cur;
}

Node* sortList(Node *head)
{
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* cur = head;
    // create separate list for 0s, 1s, 2s
    while (cur != NULL) {
        
        int value = cur -> data;
        if (value == 0) {
            insertAtTail(zeroTail, cur);
        }
        else if (value == 1) {
            insertAtTail(oneTail, cur);
        }
        else if (value == 2) {
            insertAtTail(twoTail, cur);
            
        }
        cur = cur -> next;
    }
    // merge kardo
    if (oneHead -> next != NULL)
        zeroTail -> next = oneHead -> next;
    else {
        //1s list empty hai
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
    head = zeroHead -> next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    //empty list
    if (head == NULL) {
        return NULL;
    }
    //non empty list
    Node* cur = head;
    while(cur != NULL) {
        if (cur -> next != NULL && cur -> data == cur -> next -> data) {
            Node* temp = cur -> next;
            cur -> next = cur -> next -> next;
            delete(temp);
        }
        else {
            cur = cur -> next;
        }
    }
    return head;
}
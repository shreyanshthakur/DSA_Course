Node* getMiddle (Node* head) {
    if (head == NULL || head -> next == NULL ) {
        return NULL;
    }
    //2 nodes - needed or not?
    if (head -> next -> next == NULL) {
        return head -> next;
    }
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL) {
        fast = fast -> next;
        if (fast!= NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
    
}
Node *findMiddle(Node *head) {
    // Write your code here
    return getMiddle(head);
}
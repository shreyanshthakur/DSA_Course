#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //Approach 3
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    LinkedListNode<int>* chhotaHead = reverseLinkedList(head -> next);
    
    head -> next -> next = head;
    head -> next = NULL;
    return chhotaHead;
    
    
    /*// Approach 1 (iterative)
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    LinkedListNode<int>* cur = head;
    LinkedListNode<int>* fwd = NULL;
    LinkedListNode<int>* prev = NULL;
    
    while (cur != NULL) {
        fwd = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = fwd;
    }
    return prev;
    */
}
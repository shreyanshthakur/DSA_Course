#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* solve (Node<int>* first, Node<int>* second) {
    
    if (first -> next == NULL) {
        first -> next = second;
        return first;
    }
    
    Node<int>* cur1 = first;
    Node<int>* next1 = cur1 -> next;
    Node<int>* cur2 = second;
    Node<int>* next2 = cur2 -> next;
    while (next1 != NULL && cur2 != NULL) {
        
        if ((cur2 -> data >= cur1 -> data) 
           && (cur2 -> data <= next1 -> data)) {
            //insert node in-between
            cur1 -> next = cur2;
            next2 = cur2 -> next;
            cur2 -> next = next1;
            //update pointers
            cur1 = cur2;
            cur2 = next2;
        }
        else {
            //cur1 and next1 ko aage badha do
            cur1 = next1;
            next1 = next1 -> next;
            
            if(next1 == NULL) {
                cur1 -> next = cur2;
                return first;
            }
        }
    }
    return first;
    
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if (first == NULL) 
        return second;
    if (second == NULL) 
        return first;
    
    if (first -> data <= second -> data) {
        return solve(first, second);
    }
    else {
        return solve(second, first);
    }
}

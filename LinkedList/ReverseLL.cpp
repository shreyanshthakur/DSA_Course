//repair
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail (Node* &tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}
void print (Node* &head) {
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* reverseLL (Node* &head) {
    //base case
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node* chhotaHead = reverseLL(head -> next);
    
    head -> next -> next = head;
    head -> next = NULL;
    return chhotaHead;
}

int main () {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    print(head);
    reverseLL(head);
    print(head);
    return 0;
}
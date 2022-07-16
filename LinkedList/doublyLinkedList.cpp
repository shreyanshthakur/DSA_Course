#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node (int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node () {
        int val = this -> data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for: " << val << endl;
    }
};
//traverses the LL
void print (Node* &head) {
    Node* temp = head;
    while( temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
//gives the length of LL
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead (Node* &head, Node* &tail, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail (Node* &head, Node* &tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
        return;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition (Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    int count = 1;
    Node* temp = head;
    while (count != pos-1) {
        temp = temp -> next;
        count++;
    }
    if (temp ->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
    //sabse zaruri part
    Node* node = new Node(d);
    node -> prev = temp;
    node -> next = temp -> next;
    temp -> next -> prev = node;
    temp -> next = node;
}
void deleteNode (Node* &head, Node* &tail, int pos) {
    if (pos == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        //free memory of start node
        temp -> next = NULL;
        delete temp;
    }
    else {
        //delete any position i
        Node* cur = head;
        Node* prev = NULL;

        int count = 1;
        while (count < pos) {

            prev = cur;
            cur = cur -> next;
            count++;
        }
        cur -> prev = NULL;
        prev -> next = cur -> next;
        if (count == pos) {
            tail = prev;
        }
        cur -> next = NULL;
        delete cur;
    }
}
int main () {
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(head,tail, 11);
    print(head);
    insertAtHead(head, tail, 13);
    print(head);
    insertAtHead(head, tail, 8);
    print(head);
    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 3, 99);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 7, 102);
    print(head);

    deleteNode(head, tail, 1);
    print(head);
    cout << head->data << " " << tail->data << endl;
       
    return 0;
}
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    //constructor
    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node () {
        int value = this -> data;
        if (this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory free for node with data "
        << value << endl;
    }
};

void insertAtHead (Node* &head, int d) {
    Node* temp = new Node(d);
    temp ->next = head;
    head = temp;
}
void insertAtTail (Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}
void insertAtPosition (Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, d);
        return;
    }
    int count = 1;
    Node* temp = head;
    while (count != pos-1) {
        temp = temp -> next;
        count++;
    }
    if (temp ->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}
void deleteNode (Node* &head, Node* &tail, int pos) {
    if (pos == 1) {
        Node* temp = head;
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
        
        prev -> next = cur -> next;
        if (count == pos) {
            tail = prev;
        }
        cur -> next = NULL;
        delete cur;
    }
}
void print (Node* &head) {
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main () {
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 1, 22);
    print(head);

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    deleteNode(head, tail, 4);
    print(head);
    cout << "tail " << tail -> data << endl;

    return 0;
}
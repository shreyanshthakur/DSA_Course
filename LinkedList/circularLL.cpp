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

void insertNode (Node* &tail, int element, int d) {
    //empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
        return;
    }
    //non empty list
    Node* cur = tail;
    while( cur -> data != element) {
        cur = cur->next;
    }
    //element found and cur is on it
    Node* newNode = new Node(d);
    newNode -> next = cur -> next;
    cur -> next = newNode;
}

void print (Node* &tail) {
    Node* temp = tail;
    do  {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while (temp != tail);
    cout << endl;
}

int main () {
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);
    
    return 0;
}
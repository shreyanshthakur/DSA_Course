#include <iostream>
#include<map>
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
void insertAtHead (Node* &head, int d) {
    Node* temp = new Node(d);
    temp ->next = head;
    head = temp;
}
void insertAtTail (Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
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

void print (Node* &head) {
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
bool detectLoop(Node* head) {
    if (head == NULL) {
        return  false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        //cycle is present
        if (visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node* floydDetectLoop (Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
        
    }
    return NULL;
}
Node* getStartingNode (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while( slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;

    }
    return slow;
}

void removeLoop (Node* head) {
    if (head == NULL) {
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;
}
int main () {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(head, tail, 1, 22);
    print(head);
    //loop bana do
    tail -> next = head -> next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    if (floydDetectLoop(head)) {
        cout << "LL has loop at "<< floydDetectLoop(head) -> data << endl;
    }
    else {
        cout << "LL don't have loop" << endl;
    }

    cout << "Starting at: " << getStartingNode(head) -> data << endl;
    removeLoop(head);
    print(head);
    if (floydDetectLoop(head)) {
        cout << "LL has loop at "<< floydDetectLoop(head) -> data << endl;
    }
    else {
        cout << "LL don't have loop" << endl;
    }
    return 0;
}
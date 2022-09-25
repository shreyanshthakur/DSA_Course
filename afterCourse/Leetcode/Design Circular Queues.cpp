struct Node {
public:
    int val;
    Node* next;
    Node (int v, Node* temp = nullptr) {
        val = v;
        next = temp;
    }  
};

class MyCircularQueue {
private:
    int maxsize, size = 0;
    Node* head = new Node(0);
    Node* tail = new Node(0);
public:
    MyCircularQueue(int k) {
        maxsize = k;
    }
    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value);
        if (isEmpty()) head = newNode, tail = newNode;
        else tail->next = newNode, tail = tail->next;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        Node* temp = head;
        head = head -> next;
        delete temp;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : head->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
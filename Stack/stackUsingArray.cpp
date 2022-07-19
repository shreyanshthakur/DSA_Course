#include <iostream>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

        //behavior
        Stack (int size) {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int data) {
            if (size - top > 1) {
                top++;
                arr[top] = data;
            }
            else {
                cout << "Stack OverFlow" << endl;
            }
        }

        void pop () {
            if (top >= 0) {
                top--;
            }
            else {
                cout << "Stack UnderFlow" << endl;
            }
        }
        int peek () {
            if (top >= 0) {
                return arr[top];
            }
            else {
                cout << "Stack is Emtpy" << endl;
                return -1;
            }
        }
        bool isEmpty () {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
};
int main() {

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    if (s.isEmpty()) {
        cout << "Stack is Emtpy mrer dost" << endl;
    }
    else {
        cout << "Stack is not Emtpy mere dost" << endl;
    }
    return 0;
}
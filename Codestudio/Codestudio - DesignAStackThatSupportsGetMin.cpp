#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        //for first element
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if (data < mini) {
                s.push(2*data - mini);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if (s.empty()) {
            return -1;
        }
        int cur = s.top();
        s.pop();
        if (cur > mini) {
            return cur;
        }
        else {
            int prevMin = mini;
            int val = 2*mini - cur;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        // Implement the top() function.
        if (s.empty()) {
            return -1;
        }
        int cur = s.top();
        if (cur < mini) {
            return mini;
        }
        else {
            return cur;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if (s.empty()) 
            return -1;
        else
            return mini;
    }  
};
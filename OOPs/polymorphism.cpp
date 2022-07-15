#include <iostream>
using namespace std;
//compile time polymorphism
class A {
    public:
    void sayHello() {
        cout << "Hello Shreyansh Singh" << endl;
    }

    void sayHello(string name) {
        cout << "Hello Shreyansh Singh Thakur" << endl;
    }
};

int main () {
    A obj;
    obj.sayHello("vidya");
    return 0;
}
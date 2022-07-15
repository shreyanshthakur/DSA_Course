#include <bits/stdc++.h>
using namespace std;
//compile time polymorphism
//operator overloading
class A {
    public:
    int a;

    public:
    void operator+ (A &obj) {
        cout << this -> a << endl;
        cout << obj.a;
        cout << "\nOutput : " << this->a - obj.a;
    }
    
};

int main () {
    A obj1, obj2;
    obj1.a = 7;
    obj2.a = 4;

    obj1 + obj2;
    return 0;
}
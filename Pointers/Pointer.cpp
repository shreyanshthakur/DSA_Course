#include<iostream>
using namespace std;

void pointer (int *p) {
    cout << *p;
}

int main() {
    int value = 5;
    int *p = &value;
    pointer(p);
}

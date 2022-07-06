#include <iostream>
using namespace std;
//Euclid Algorithm to find Greatest Common Divisor
int gcd (int a, int b) {
    if(a==0)
        return b;
    if(b==0)
        return a;
    while (a != b) {
        if (a < b) {
            b = b - a;
        }
        else {
            a = a - b;
        }
    }
    return a;
}
int main () {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
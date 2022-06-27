#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {

    int bitCount = 0;
    //edge case
    if (n == 0) {
        return false;
    }
    while (n != 0) {
        int bit = n & 1;
        if (bit == 1) {
            bitCount++;
        }
        if (bitCount > 1) {
            return false;
        }
        n = n>>1;
    }
        return true;
}
int main () {
    int n;
    cin >> n;
    if (isPowerOfTwo(n)) {
        cout << n << " is power of two";
    }
    else cout << n << " is not power of two";
    return 0;
}
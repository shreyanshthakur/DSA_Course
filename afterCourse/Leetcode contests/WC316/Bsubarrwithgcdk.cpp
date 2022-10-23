#include <bits/stdc++.h>
using namespace std;

int subarrayGCD(vector<int>& a, int k) {
    int n = a.size(), count = 0;
    for (int i = 0; i < n; i++) {
        int curgcd = a[i];
        for (int j = i; j < n; j++) {
            curgcd = __gcd (curgcd, a[j]);
            if (curgcd == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> a = {9,3,1,2,6,3};
    int k = 3;
    cout << "Running" << endl;
    cout << subarrayGCD (a, k) << endl;
    cout << "Completed" << endl;
    return 0;
}
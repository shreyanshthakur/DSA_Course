#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a%2 == 1 && b%2 == 1) {
        cout << "No" << endl;
    }
    else if (a == 1 || b == 1) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
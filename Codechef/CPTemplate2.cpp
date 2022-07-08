#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    if (n <= x) {
        cout << 0 << endl;
    }
    else {
        int pkt = 0;
        while (n > x) {
            x = x + 4;
            pkt++;
        }
        cout << pkt << endl;
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
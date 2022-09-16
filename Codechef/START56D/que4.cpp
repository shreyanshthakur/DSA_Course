#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    int color = 0;
    if (r) color++;
    if (g) color++;
    if (b) color++;
    if (r & g) color++;
    if (g & b) color++;
    if (r & b) color++;
    cout << color << "\n";
    
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
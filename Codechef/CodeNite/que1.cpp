#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> m >> n;
    int p[m];
    int r[n];
    map<int, int> available;
    map<int, int> tobuy;
    for (int i = 0; i < m; i++) {
        cin >> p[n];
        available[p[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> r[n];
        tobuy[r[i]]++;
    }
    //debug
    for (auto i : available) cout << i << " ";
    cout << endl;
    for (auto i : tobuy) cout << i << " ";
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     if (available[r[i]] < tobuy[r[i]]) {
    //         cout << "NO" << "\n";
    //         return;
    //     } 
    // }
    // cout << "YES" << "\n";
    // return;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
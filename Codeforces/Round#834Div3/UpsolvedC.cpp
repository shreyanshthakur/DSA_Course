#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    ll l, r, x, a, b;
    cin >> l >> r >> x;
    cin >> a >> b;
    
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    else if (a < b) {
        if (b-a >= x) {
            cout << 1 << endl;
        }
        else if (r-b >= x || a-l >= x) {
            cout << 2 << endl;
        }
        else if (r-a >= x && b-l >= x) {
            cout << 3 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        if (a-b >= x) {
            cout << 1 << endl;
        }
        else if (r-a >= x || b-l >= x) {
            cout << 2 << endl;
        }
        else if (r-b >= x && a-l >= x) {
            cout << 3 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
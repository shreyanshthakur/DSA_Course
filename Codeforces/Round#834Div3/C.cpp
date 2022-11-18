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
    if ((r-l) < x) {
        cout << -1 << endl;
        return;
    }
    if (abs(a-b) >= x) {
        cout << 1 << endl;
        return;
    }
    else {
        if ((r-b) >= x && (b-l) >= x) {
            cout << 2 << endl;
            return;
        }
        else {
            cout << 3 << endl;
            return;
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
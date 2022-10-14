#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) cout << 0 << endl;
    else if ((int)sqrt(x*x + y*y) == sqrt(x*x + y*y)) cout << 1 << endl;
    else cout << 2 << endl;
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
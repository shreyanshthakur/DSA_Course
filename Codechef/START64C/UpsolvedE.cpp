#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < 2*n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    int maxi = n + (n+1)/2;
    for (auto i : m) {
        if (i.second > maxi) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
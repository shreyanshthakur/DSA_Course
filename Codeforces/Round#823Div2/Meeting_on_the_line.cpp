#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define M 1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), t(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max (maxi, x[i] + t[i]);
        mini = min (mini, x[i] - t[i]);
    }
    cout << (maxi+mini)/2.0 << endl;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
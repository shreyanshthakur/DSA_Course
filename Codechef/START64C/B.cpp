#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    int a[n];
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max (maxi, a[i]);
    }
    cout << maxi << endl;
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
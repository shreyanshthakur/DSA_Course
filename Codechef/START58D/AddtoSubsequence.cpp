//upsolved
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    int maxi = INT_MIN;
    for (auto i : m) {
        if (maxi < i.second) 
            maxi = max (maxi, i.second);
    }
    int val = 1, ans = 0;
    while (val < maxi) {
        ans++;
        val *= 2;
    }
    cout << ans << endl;
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
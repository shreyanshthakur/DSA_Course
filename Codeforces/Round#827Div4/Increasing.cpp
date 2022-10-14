#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int a[n];
    bool flag = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] > 1) flag = 1;
    }
    if (flag == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
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
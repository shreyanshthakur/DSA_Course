#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n+1] = {0};
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<pair<int, int>> ans;
    bool isequal = (a[0] == b[0]);
    for (int i = 0; i < n; i++) {
        if ((a[i] == b[i]) != isequal) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            ans.push_back({i+1, i+1});
            isequal = 1;
        }
    }
    
    if (!isequal) {
        ans.push_back({1, n});
        ans.push_back({2, n});
        ans.push_back({1, n});
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto &x : ans) {
        cout << x.first << " " << x.second << endl;
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
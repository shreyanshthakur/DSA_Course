#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i-1] == s[i]) {
            count++;
        }
    }
    cout << count << endl;
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
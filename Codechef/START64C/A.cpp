#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string a = s.substr(0, (n/2));
    string b = s.substr(n/2, n-1);
    //cout << a << " " << b << endl;//debug
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
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
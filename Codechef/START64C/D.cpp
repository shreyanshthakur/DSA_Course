#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[0] == a[n-1]) {
        cout << "YES" << endl;
        return;
    } 
    else if (a[0] == a[n-2]) {
        cout << "YES" << endl;
        return;
    } 
    else if (a[1] == a[n-1]) {
        cout << "YES" << endl;
        return;
    } 
    ll i = 1;
    while (i < n) {
        while (a[i] != a[0] && i < n-1) i++;
        if (i < n-1 && a[i+1] == a[n-1]) {
            cout << "YES" << endl;
            return;
        }
        i++;
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
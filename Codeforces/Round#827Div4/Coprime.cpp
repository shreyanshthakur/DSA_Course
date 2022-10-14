#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxi = INT_MIN;
    bool flag = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (__gcd(a[i], a[j]) == 1) {
                maxi = max (maxi, i+j+2);
                flag = 1;
            }
        }
    }
    if (flag) cout << maxi << endl;
    else  cout << -1 << endl;
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
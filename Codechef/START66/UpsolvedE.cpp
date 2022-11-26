#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    bool flag = 1;
    int i = 0, j = n-1;
    while (i < j) {
        if (v[i++] != v[j--]) flag = 0;
    }

    if (flag) cout << 0 << endl;
    else {
        ll int l = 0, r = n-1;
        ll int ans = 0;
        while (l < r) {
            if (v[l] == v[r]) {
                l++; 
                r--;
            }
            else if (v[l] > v[r]) {
                v[l] -= v[r];
                ans++;
                r--;
            } 
            else {
                v[r] -= v[l]; 
                ans++; 
                l++;
            }
        }
        cout << ans << endl;
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
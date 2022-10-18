#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = n-1, mini = INT_MAX, ans = 0;
    while (i >= 0) {
        if (s[i] == '1') {
            mini = arr[i];
            while (i >= 0) {
                mini = min (mini, arr[i]);
                if (s[i] == '1') {
                    ans += arr[i];
                    i--;
                }
                else {
                    ans += arr[i];
                    ans -= mini;
                    i--;
                    break;
                }
            }
        }
        else {
            i--;
        }
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
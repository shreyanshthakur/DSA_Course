#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if ((arr[i]%2) == 1) arr[i]--;
    }
    sort (arr, arr+n);
    int ans = 0, i = 0, j;
    while (i < n) {
        j = i;
        while (arr[i] == arr[j] && i < n) {
            i++;
        }
        ans = max (ans , i-j);
    }
    cout << n - ans << endl;
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
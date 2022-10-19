#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    int arr[n];
    int count1 = 0, count0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) count1++;
        if (arr[i] == 0) count0++;
    }
    int ans = 0;
    while (count0 && count1) {
        ans++;
        count0--;
        count1--;
    }
    if (count1) {
        ans += count1/3;
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
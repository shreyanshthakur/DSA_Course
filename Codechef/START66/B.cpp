#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0, count = 0;
    while (n != 1) {
        ans += a;
        n /= 2;
        //cout << "n= " << n;
        count++;
    }
    //cout << ans << " " << count << endl;
    cout << ans + ((count-1)*b) << endl;
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
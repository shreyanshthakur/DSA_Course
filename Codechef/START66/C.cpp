#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n, m, k, x; 
    cin >> n >> m >> k >> x;
    int rem = x % ((n*k) + m);
    if (rem > (k-1) * n || rem == 0) cout <<"Yes" << endl;
    else cout << "No" << endl;
    
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
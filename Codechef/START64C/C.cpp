#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
void solve() {
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
    }
    
    int cntgcd = 0;
    for (int i = 0; i < n; i++) {
        if (g == a[i]) {
            cntgcd++;
        }
    }
    cout << n-cntgcd << endl;
    
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        //cout << "TC-" << t << endl;//debug 
        solve();
    }
    return 0;
}
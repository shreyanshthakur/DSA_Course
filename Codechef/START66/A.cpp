#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a>b+c || b>a+c || c>a+b)
        cout << "Yes" << endl; 
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
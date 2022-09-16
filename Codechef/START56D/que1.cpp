#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> v;
    long long int maxi = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // v.push_back(x);
        maxi += max (abs(x-1), abs(x-m));
    }
    // long long int maxi = 0;
    // for (int i = 0; i < n; i++) {
    //     maxi += max (abs(v[i]-1), abs(v[i]-m));
    // }
    cout << maxi << "\n";
    
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
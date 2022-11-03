#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
    int maxi = INT_MIN;
    for (auto &i : m) {
        int sum = i.second;
        if (i.first%2 == 0 && m.find(i.first+1) != m.end()) {
            sum += m[i.first+1];
        }
        maxi = max (maxi, sum);
    }
    cout << n-maxi << endl;
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
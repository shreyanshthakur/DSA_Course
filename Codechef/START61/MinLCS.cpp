#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int a[26] = {0}, b[26] = {0};
    for (auto &c : s1) {
        a[c-'a']++;
    }
    for (auto &c : s2) {
        b[c-'a']++;
    }
    int maxcount = INT_MIN, maxi = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] && b[i]) {
            maxi = min (a[i], b[i]);
        }
        maxcount = max (maxcount, maxi);
    }
    cout << maxcount << endl;
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
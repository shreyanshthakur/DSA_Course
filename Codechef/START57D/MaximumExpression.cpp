#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int plus = 0;
    int minus = 0;
    vector<char> v;
    for (int i = 0; i < n; i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            v.push_back(s[i]);
        }
        if (s[i] == '+') plus++;
        if (s[i] == '-') minus++;
    }
    sort(v.begin(), v.end(), greater<int>());
    string ans = "";
    for (int i = 0; i < v.size()-(plus+minus); i++) {
        ans += v[i];
    }
    for (int i = v.size()-(plus+minus); i < v.size(); i++) {
        if (plus-->0) {
            ans += '+';
        }
        else ans+= '-';
        ans += v[i];
    }
    cout << ans << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
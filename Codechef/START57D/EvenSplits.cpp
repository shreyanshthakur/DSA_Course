#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n>2) {
        sort(s.begin(), s.end());
        cout << s << endl;
    }
    else {
        cout << s << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
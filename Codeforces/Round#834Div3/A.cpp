#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    int i = 0, j = 0;
    string x = "Yes";
    if (s[i] == 'Y') {
        j = 0;  
    }
    else if (s[i] == 'e') {
        j = 1;
    }
    else if (s[i] == 's') {
        j = 2;
    }
    else {
        cout << "No" << endl;
        return;
    }
    while (i < s.length()) {
        j %= 3;
        if (s[i] != x[j]) {
            cout << "No" << endl;
            return;
        }
        i++;
        j++;
    }
    cout << "Yes" << endl;
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
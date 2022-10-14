#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    char a[8][8];
    int countR = 0;
    bool flag = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') countR++;
        }
        if (countR == 8) {
            flag = 1;
        }
        countR = 0;
    }
    if (flag == 1) cout << 'R' << endl;
    else cout << 'B' << endl;
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
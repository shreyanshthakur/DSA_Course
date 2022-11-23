#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    //check palindrome
    int i = 0, j = s.length()-1;
    bool flag = 0;
    while (i < j) {
        if (s[i++] != s[j--]) {
            flag = 1;
            break;
        }

    }
    if (flag == 1) cout << 2 << endl;
    else cout << s.length()-2 << endl;
    
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
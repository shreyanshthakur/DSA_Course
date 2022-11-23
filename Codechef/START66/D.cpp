#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    
    if (s[0] == s[s.length()-1]) cout << s.length()-2 << endl;
    else cout << 2 << endl;   
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
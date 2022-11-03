#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    int count1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            count1++;
        }
        if (s[i] == '0' || i == n-1) {//minute mistake = yaha i ko s[i] likh raha tha 
            if ((count1%2) == 1) {
                cout << "NO" << endl;
                return;
            }
            count1 = 0;
        }   
    }
    cout << "YES" << endl;
    return;
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
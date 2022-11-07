#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007
//Resolved - pretest 5 failed
//Error - used int instead of long long int
void solve() {
    int n; 
    cin >> n;
    string s;
    cin >> s;
    long long int count1 = 0, count0 = 0, ans1 = 0, ans0 = 0, cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            count0++;
            ans1 = max (ans1, count1);
            count1 = 0;
            cnt0++;
        }
        else {
            count1++;
            ans0 = max (ans0, count0);
            count0 = 0;
            cnt1++;
        }
    }
    ans1 = max (ans1, count1);
    ans0 = max (ans0, count0);
    cout << max (ans1 * ans1, max(ans0 * ans0, cnt1 * cnt0) ) << endl;
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
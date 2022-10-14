#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; 
    cin >> n;
    int a, b, c, count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a+b+c >= 2) count++;
    }
    cout << count << endl;
}

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    solve ();
    return 0;
}
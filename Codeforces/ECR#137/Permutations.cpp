#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int count = 1;
    for (int i = 0; i < n; i=i+2) {
        arr[i] = count++;
    }
    count = n;
    for (int i = 1; i < n; i=i+2) {
        arr[i] = count--;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
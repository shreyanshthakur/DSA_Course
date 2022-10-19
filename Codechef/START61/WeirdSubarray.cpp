#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n-1 && arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
            count++;
        }
    }
    cout << ((n * (n+1)) / 2) - count << endl;
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
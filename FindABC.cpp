#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        ans = (a ^ i) + (b ^ i) + (c ^ i);
        if (ans == arr[i]) {
            cout << a << b << c << endl;
            return;
        }
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
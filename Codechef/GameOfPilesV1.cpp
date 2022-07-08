//repair 
//two testcases out of 6 failed
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    int arr[n];
    bool ans = 0;
    int count2 = 0;
    long long int sumarr = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            ans = 1;
        }
        if (arr[i] == 2) {
            count2++;
        }
        sumarr += arr[i];
    }
    if (ans == 1) {
        cout << "Chef" << endl;
        return;
    }
    else if (count2 == n-1) {
        cout << "Chefina" << endl;
        return;
    }
    if ((sumarr - 2*n) % 2 == 0) {
        cout << "Chefina" <<endl;
    }
    else {
        cout << "Chef" << endl;
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
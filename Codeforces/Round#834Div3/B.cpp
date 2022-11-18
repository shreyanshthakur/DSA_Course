#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void solve() {
    int m, absentSum, presentSum = 0, finalSum, maxi = INT_MIN;
    cin >> m >> absentSum;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        presentSum += tmp; 
        maxi = max (maxi, tmp);
    }
    finalSum = absentSum + presentSum;
    //cout << "finalSum = " << finalSum << endl;//debug
    int i = maxi;
    while (1) {
        int t = finalSum - (i * (i+1))/2;
        //cout << "t " << i << " = " << t << endl;//debug
        if (t == 0) {
            cout << "Yes" << endl;
            return;
        }
        else if (t < 0) {
            cout << "No" << endl;
            return;
        }
        i++;
    }
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
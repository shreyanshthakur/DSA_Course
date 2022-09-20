#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long int a[n+1];
        for (long long int i = 1; i <= n; i++)
            cin >> a[i];
   
        long long int maxSum = 0;
        long long int maxi = INT_MIN;    
        for (long long int i = 1; i <= k; i++) {
            maxi = INT_MIN;
            for (long long int j = i; j <= n; j += k) {
                maxi = max (maxi, a[j]);
            }
            // cout << maxi << " ";
            maxSum += maxi;
        }
        cout << maxSum << "\n";
    }
    return 0;
}
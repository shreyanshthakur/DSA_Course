#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n+1];
        
        //step 1: map mein freq store karlo
        int mapping[n+1] = {};
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            mapping[arr[i]]++;
        }
        
        //step 2: sort karo mapping ko decreaing order mein
        int x = sizeof(mapping) / sizeof(mapping[0]);
        sort(mapping, mapping + x, greater<int>());
        int maxi = mapping[0];
        int secMax = mapping[1];
        //step 3: highest freq nikalo
        if (maxi%2 == 0)
            cout << max( (maxi/2), secMax ) << endl;
        else {
            cout << max( (maxi/2)+1, secMax ) << endl;
        }
    }
    return 0;
}
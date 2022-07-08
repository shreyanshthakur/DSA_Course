#include <bits/stdc++.h>
using namespace std;

void solve() {
    int maxt, maxn, sumn;
    cin >> maxt >> maxn >> sumn;
    int curn = 0;
    long long int sumitr = 0;
    int t = 1;
    while (sumn != 0 && t <= maxt) {
        
        if (sumn - maxn >= 0) {
            curn = maxn;
            sumitr += curn*curn;
            sumn -= maxn;
            
            t++;
        }
        else {
            curn = sumn;
            sumn = 0;
            sumitr += curn*curn;
            t++;
        }
        
    }
    cout << sumitr << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
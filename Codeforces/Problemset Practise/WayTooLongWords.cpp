#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i]; 
    }
    for (int i = 0; i < n; i++) {
        if (s[i].length() > 10) {
            string ans = "";
            ans += s[i][0] + to_string(s[i].length()-2) + s[i][s[i].length()-1];
            cout << ans << "\n";
            continue;
        }
        else 
        cout << s[i] << "\n";
    }
    return 0;
}
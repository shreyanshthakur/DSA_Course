#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007

void recursion (int arr[], string &s, int mags, int x, int y, vector<int>& v) {
    //base case
    if (y > s.length()) {
        return;
    }
    //swap
    if (s[x] == 0 && s[y] == 1) {
        v.push_back(mags-arr[y]+arr[x]);
        recursion (arr, s, mags-arr[y]+arr[x], x+1, y+1, v);
    }
    //Noswap
    recursion (arr, s, mags, x+1, y+1, v);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mags;
    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            mags += arr[i];
        }
    }
    vector<int> v;
    v.push_back(mags);
    recursion (arr, s, mags, 0, 1, v);
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
       maxi = max (maxi , v[i]);
    }
    cout << maxi << endl;
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
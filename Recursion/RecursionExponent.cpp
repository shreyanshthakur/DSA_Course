#include <bits/stdc++.h>
using namespace std;

int exponent(int a, int b) {
    
    //base case
    if (a == 0) 
        return 0;
    if (a == 1 || b == 0) 
        return 1;
    if (b == 1) 
        return a;

    //recursive call
    int ans = exponent(a, b/2);
    if (b&1)
        return ans * ans * a;
    else 
        return ans * ans;
}

int main () {
    int a, b;
    cin >> a >> b;
    cout << exponent(a, b);
    return 0;
}
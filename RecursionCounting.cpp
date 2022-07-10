#include <bits/stdc++.h>
using namespace std;

void counting (int n) {

    //base case
    if (n == 0) {
        return;
    }
    cout << n << " ";
    //recursive relation
    counting(n-1);  
}

int main () {
    int n;
    cin >> n;
    counting(n);
    return 0;
}
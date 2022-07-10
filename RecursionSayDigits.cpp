#include <bits/stdc++.h>
using namespace std;

string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void sayDigit (int n) {
    //base case
    if (n == 0) {
        return;
    }
    //recursive relation
    sayDigit(n/10);

    //processing
    n = n % 10;
    cout << arr[n] << " ";


}

int main () {
    int t;
    cin >> t;
    
    sayDigit(t);

    return 0;
}
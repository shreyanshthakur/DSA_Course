//to be repaired
#include <iostream>
using namespace std;
long long int sqrt (int n) {
    int s = 1;
    int e = n;
    long long int mid = s + (e-s)/2;
    int ans;
    while (s <= e) {
        //precalculate mid*mid
        long long int square = mid*mid;
        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
double morePrecision (int precision, int tempsol, int n) {
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++) {
        factor = factor / 10;
        for (long long int j = ans; j * j < n; j += factor) {
            ans = j;
            cout << j << " ";
        }
    }
    return ans;
}
int main () {
    int n;
    cin >> n;
    int tempsol = sqrt(n);
    cout << tempsol;
    cout << morePrecision(3, tempsol, n);
    return 0;
}
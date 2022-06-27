#include<iostream>
#include<math.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int INT_MAX = 2147483647;
    int INT_MIN = -2147483647;
    int ans = 0;
    int flag = 0;
    while (n != 0) {
        int digit = n % 10; 
        if ((ans > INT_MAX/10) || (ans < INT_MIN*10)) {
            cout << "0";
            flag = 1;
            
        }
        ans = (ans * 10) + digit;
        n = n/10;
    }
    if (flag == 0) {
        cout << ans;
    }
    return 0;
}
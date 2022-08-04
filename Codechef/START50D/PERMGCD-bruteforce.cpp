#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

void solve (int arr[], int jagah, bool &flag, int x) {
    flag = 0;
    int gcdsum = arr[0];
    if (gcdsum == x && jagah == 1) {
        cout << "1" << endl;
        flag = 1;
        return;
    }
        
    int result = arr[0];
    for (int i = 1; i < jagah; i++) {
        
        if (result != 1)
            result = gcd(arr[i], result);
            
        gcdsum += result;
        
        if (gcdsum == x) {
            
            for (int i = 0; i < jagah; i++) {
                cout << arr[i] << " ";
                flag = 1;
            }
            cout << '\n';
            return ;
        }
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        //step 1: create an array of size n 
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i+1;
        }
        
        //step 2: find all permutations
        int jagah = sizeof(arr) / sizeof(arr[0]);
        bool flag = 0;
        do {
            solve (arr, jagah, flag, x);
            if (flag == 1)
                break;
            
        } while (next_permutation(arr, arr + jagah));
        
        //if solution not possible
        if(flag == 0) {
            cout << "-1" << endl;
        }
    }
    return 0;
}
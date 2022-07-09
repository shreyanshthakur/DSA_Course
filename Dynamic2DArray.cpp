#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    //single line array jisme pointers rakhe
    int** arr = new int*[n];
    //array ke har box me ek array rakha
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //releasing memory
    for (int i = 0; i < n; i++) {
        delete []arr[i];
    }
    delete []arr;

    return 0;
}
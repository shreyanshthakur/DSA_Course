#include <bits/stdc++.h>
using namespace std;

void sort01 (int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (arr[i] == 0 && i < j) i++;
        while (arr[j] == 1 && i < j) j--;
        while (arr[i] == 1 && arr[j] == 0 && i < j) {
            swap(arr[i], arr[j]);
        }
    }
}
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main () {
    int arr[10] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 0};
    sort01(arr, 10);
    printArray(arr, 10);

    int brr[10] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    sort01(brr, 10);
    printArray(brr, 10);
    return 0;
}
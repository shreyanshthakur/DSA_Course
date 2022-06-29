#include <iostream>
using namespace std;

void sort01 (int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]==1) {
            count++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < n - count) {
            arr[i] = 0;
        }
        else {
            arr[i] = 1;
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
#include <iostream>
using namespace std;

void swapAlternate (int arr[], int size) {
    int i = 0;

    while (i + 1 < size)  {
        swap(arr[i], arr[i + 1]);
        i += 2;
    }
}

void printArray (int arr[], int size) {
    //print array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//driver code
int main () {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int brr[5] = {2, 5, 3, 6, 2};
    swapAlternate(arr, 10);
    printArray(arr, 10);

    swapAlternate(brr, 5);
    printArray(brr, 5);

    return 0;
}
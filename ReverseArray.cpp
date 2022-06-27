#include <iostream>
using namespace std;
//overloaded swap function
void swap (int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void reverseArray (int arr[], int size) {
    //reverse array
    for (int i = 0; i < size / 2; i++) {
        swap(arr + i, arr + size - 1 - i);
    }
}
void printArray (int arr[], int size) {
    //print array
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
int main () {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseArray(arr, 10);
    printArray(arr, 10);
    return 0;
}
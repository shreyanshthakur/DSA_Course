#include <iostream>
using namespace std;

void swap (int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void reverseArray (int arr[], int size) {
    
    int tmp;
    for (int i = 0; i < size / 2; i++) {
        swap(arr + i, arr + size - 1 - i);
    }
}
int main () {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseArray(arr, 10);
    //print array
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
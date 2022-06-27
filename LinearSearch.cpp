#include <iostream>
using namespace std;

int linearSearch (int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main () {
    int arr[100] = {2, 3, 5, 3, 5, 6, 6, 1, -25, 33};

    int key;
    cin >> key;

    if (linearSearch(arr, 100, key) != -1) {
        cout << key << " is present at position " << linearSearch(arr, 100, key) + 1; 
    }

    return 0;
}
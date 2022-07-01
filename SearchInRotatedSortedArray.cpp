#include <iostream>
using namespace std;
int pivotElement (int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch (int arr[], int s, int e, int key) {
    int start, end, mid;
    start = 0;
    end = e;
    mid = start + (end - start) / 2;
    while (start <= end) {
        if (arr[mid] == key) return mid;
        if(key > arr[mid]) start = mid + 1;
        else end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main () {
    int arr[5] = {7, 9, 1, 2, 3};
    int pivot = pivotElement(arr, 5);
    int key = 3;
    int n = 5;
    if (arr[pivot] <= key && key <= arr[n-1]) {
        cout << binarySearch(arr, pivot, n - 1, key);
    }
    else {
        cout << binarySearch(arr, 0, pivot-1, key);
    }
    return 0;
}
#include <iostream>
using namespace std;
int binarySearch (int arr[], int n, int key) {
    int start, end, mid;
    start = 0;
    end = n - 1;
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
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int brr[5] = {6,7,8,9,10};
    cout << binarySearch(arr, 6, 4) << endl;
    cout << binarySearch(brr, 5, 10); 
    return 0;
}
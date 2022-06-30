#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while (s <= e) {
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
           
            e = mid - 1;
        }
        else {
             s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}
int main () {
    int arr[5] = {5, 4, 3, 2, 1};
    cout << binarySearch(arr, 5, 4);    
    return 0;
}
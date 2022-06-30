#include <iostream>
using namespace std;
int firstOcc (int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOcc (int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = s + 1;
        }
        else if (arr[mid] < key) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main () {
    int arr[7] = {0, 0, 1, 1, 2, 2, 2};
    cout << firstOcc(arr, 7, 2) << endl;
    cout << lastOcc(arr, 7, 2);
    return 0;
}
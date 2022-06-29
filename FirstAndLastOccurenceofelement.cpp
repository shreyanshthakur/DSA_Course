#include <iostream>
using namespace std;

int firstocc (int arr[], int n, int key) {
    int s = 0, e = n - 1, mid = s + (e - s) / 2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid]) s = mid + 1;
        else if (key < arr[mid]) e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int secondocc (int arr[], int n, int key) {
    int s = 0, e = n - 1, mid = s + (e - s) / 2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid]) s = mid + 1;
        else if (key < arr[mid]) e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main () {
    int arr[9] = {0, 0, 1, 1, 1, 2, 2, 2, 2};
    cout << "First occurence is " << firstocc(arr, 9, 1) << endl;

    cout << "Second occurence is " << secondocc(arr, 9, 1);
    

    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isSorted (int arr[], int size) {
    //base case
    if (size == 0 || size == 1) 
        return true;
    if (arr[0] > arr[1]) 
        return false;
    else {
        return isSorted(arr+1, size-1);
    }
    //recursive call
    

}

int main () {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << isSorted(arr, 5);
    return 0;
}
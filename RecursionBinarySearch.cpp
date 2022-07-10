#include <bits/stdc++.h>
using namespace std;

bool binarySearch (int arr[], int s, int e, int k) {
    //base case
    int mid = s + (e-s)/2;
    if (arr[mid] == k)
        return true;
    if (s > e) 
        return false;
    if (arr[mid] < k)
        return binarySearch(arr, mid+1, e, k);
    else
        return binarySearch(arr, s, mid-1, k);
}

int main () {
    int arr[6] = {2, 4, 6, 10, 14, 16};
    int k = 15;
    int s = 0;
    int e = 5;
    cout << binarySearch(arr, s, e, k);
    return 0;
}
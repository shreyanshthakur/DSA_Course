#include <iostream>
using namespace std;

int sumOfArray (int arr[], int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
int main () {
    int size;
    cin >> size;
    int arr[100000];

    //input array
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Sum of array is : " << 
    sumOfArray(arr, size);
    return 0;
}
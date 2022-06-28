//only for non negative elements
#include <iostream>
using namespace std;
void isUniqueOcc(int arr[], int size) {
    int visited[2001] = {0};
    for (int i = 0; i < size; i++) {
        visited[arr[i]]++;
    }
    for (int i = 0; i < 2001; i++) {
        if (visited[i] != 0) {
            cout << visited[i] << " ";
        }
    }
}
int main () {
    int arr[10] = {-3,0,1,-3,1,1,1,-3,10,0};
    isUniqueOcc(arr, 10);
    /*if (isUniqueOcc(arr, 10)) {
        cout << "Yes each element occurence is unique";
    }
    else {
        cout << "Nope";
    }*/
    return 0;
}
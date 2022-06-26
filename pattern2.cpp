#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int row = 1;
    while (row <= n) {
        int space = 1;
        //space print 
        while (space <= n - row) {
            cout << " ";
            space++;
        }
        //bottom right triangle print
        int col = 1;
        while (col <= row) {
            cout << col;
            col++;
        }
        //bottom left triangle print with -1
        int value = row - 1;
        while (value >= 1) {
            cout << value;
            value--;
        }
        cout << "\n";
        row++;
    }
    return 0;
}
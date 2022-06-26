//prints a complex pattern using only while loop
/*1234554321
  1234**4321
  123****321
  12******21
  1********1  */
#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int row = 1;
    while (row <= n) {
        //upper left number triangle  
        /*12345
          1234
          123
          12
          1*/
        int col = 1;
        while (col <= n - row + 1) {
            cout << col;
            col++;    
        }
        //bottom right star triangle
        /* *
          **
         *** 
        **** */
        col = 1;
        while (col <= row - 1) {
            cout << "*";
            col++;
        }
        //bottom left star triangle
        col = 1;
        while (col <= row - 1) {
            cout << "*";
            col++;
        }
         //upper right number triangle
        col = 1;
        int value = n - row + 1;
        while (col <= n - row + 1) {
            cout << value;
            col++;
            value--;        
        }
        row++;
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int charLength(char ch[]) {
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++) {
        count++;
    }
    return count;
}
int main () {
    char ch[4] = {'a', 'b', 'c'};
    string s = "ab\0c";
    //s.push_back('\0');
    //s.push_back('c');
    for (int i = 0; i < 4; i++) 
        cout << ch[i];
    cout << endl << s;
    cout << endl; 

    cout << charLength(ch);

    return 0;
}
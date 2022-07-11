#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& s, int i, int j) {
    //base case
    if(i>j)
        return 1;
    if(s[i] != s[j])
        return 0;

    //recursive call
    return checkPalindrome(s, i+1, j-1);
}

int main () {
    string s = "abbccbba";
    cout << checkPalindrome(s, 0, s.length() -1);
    return 0;
}
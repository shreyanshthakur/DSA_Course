#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseString(string c) {
        int s = 0;
        int e = c.size() - 1;
        while (s<e) {
            swap(c[s++], c[e--]);
        }
        return c;
}

string wordSeparate(string s) {
    int i = 0;
    //int s = 0;
    string ans = "";
    string temp = ""; 
    int n = s.length();
    while(i <= n) {
        
        if (s[i] == ' ') {
            ans = ans + reverseString(temp);
            ans.push_back(' ');
            temp = "";
        }
        else if (i == n) {
            ans = ans + reverseString(temp);
        }
        else {
            temp.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

int main () {
    string s = "The sky is blue";
    
    string b = "  , ";
    cout << s << endl;
    cout << wordSeparate(s)<< endl;

    cout << b << endl;
    cout << wordSeparate(b);
    return 0;
}
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool checkAnagram(string s1, string s2) {
    if (s1 == s2)
        return 0;
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2)
        return 0;

    int count = 0;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) {
        return 1;
    }
    return 0;
}

//driver code
int main() {
    string words[] = {"cat", "silent", "listen", "salient"};
    int count = 0;
    unordered_map<int, string> m;
    for (int i = 0; i < 4; i++) {
        count++;
        for (int j = 0; j < 4; j++) {
            if (checkAnagram (words[i], words[j])) {
                count--;
            }
        }
    }
    cout <<count;
    return 0;
}
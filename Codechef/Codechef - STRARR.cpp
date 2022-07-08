#include <iostream>
using namespace std;

void solution() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    char last = '-';
    for (char bit : s) {
        if (last == '1' &&  bit == '0') {
            count++;
        }
        last = bit;
    }
    cout << count << "\n";
    
}

int main() {
	// your code goes here
	int t; 
	cin >> t;
	while (t--) solution();
	
	return 0;
}

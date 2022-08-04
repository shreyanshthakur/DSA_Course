#include <iostream>
using namespace std;
//take-away: permutation wale que mein bruteforce lagane 
//se pehle paper work karo, kahi math se hojaega kya
int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, x;
	    cin >> n >> x;
	    if (n > x)
	        cout << "-1" << endl;
	    else {
	        int num = x - n + 1;
	        cout << num << " ";
    	    for (int i = 1; i <= n; i++) {
    	        if (i == num) 
    	            continue;
                cout << i << " ";
    	    } cout << "\n";
	    }
	    
	}
	return 0;
}

#include <iostream>
using namespace std;
void solve() {
    int n; 
	    cin >> n;
	    int p[n];
	    int occ[n+1] = {0};
	    for (int i = 0; i < n; i++) {
	        cin >> p[i];
	        occ[p[i]]++;
	    }
	   
	    int flag = 0;
	    for (int i = 1; i <= n; i++) {
	        if (occ[i]%i != 0) {//Yaha Gadbad kar rha tha bas
	            cout << "NO" <<endl;
	            flag = 1;
	            break;
	        }
	    }
	    if (flag == 0)
	        cout << "YES" << endl;
}
int main() {
	// your code goes here
	int t; cin>> t;
	while (t--) {
	    solve();
	}
	return 0;
}

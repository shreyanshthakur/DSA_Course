#include <iostream>
using namespace std;

void solution() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int distance = abs(x2 - x1) + abs(y2 - y1);
    if(distance&1){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) solution();
	return 0;
}

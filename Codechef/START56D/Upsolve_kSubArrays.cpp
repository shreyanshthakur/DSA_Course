#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t;
	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    int gcdOfAll = 0;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        gcdOfAll = __gcd(gcdOfAll, arr[i]);
	    }
	    int index = 0;
	    int subarrayCount = 0;
	    int curSubarrayGCD = 0;
	    while (index < n && subarrayCount < k) {
	        curSubarrayGCD = 0;//update to zero for every subarray
	        while (index < n && curSubarrayGCD != gcdOfAll) {//index < n to terminate the loop if in case 2nd condition never false
	            curSubarrayGCD = __gcd(curSubarrayGCD, arr[index]);
	            index++;
	        }
	        if (curSubarrayGCD == gcdOfAll)
	            subarrayCount++;
	    }
	    if (subarrayCount == k) 
	        cout << "YES" << "\n";
	    else 
	        cout << "NO" << "\n";
	}
	return 0;
}

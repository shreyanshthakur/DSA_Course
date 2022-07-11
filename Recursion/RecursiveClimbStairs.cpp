#include <bits/stdc++.h>
using namespace std;

int countDistinctWayToClimbStair(long long nStairs)
{
    //  Write your code here.
    if (nStairs < 0)
        return 0;
    if (nStairs == 0)
        return 1;
    
    return countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs-2);
}

int main () {
    int n;
    cout << "Enter no. of stairs: ";
    cin >> n;
    
    cout << countDistinctWayToClimbStair(n);
    return 0;
}
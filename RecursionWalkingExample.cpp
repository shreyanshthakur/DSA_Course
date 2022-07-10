#include <bits/stdc++.h>
using namespace std;

void reachHome (int start, int destination) {

    //base case
    if (start == destination) {
        cout << "Pahuch Gaya";
        return;
    }

    //processing
    start = start + 1;

    //recusive call
    return reachHome(start, destination);
}

int main () {
    int start = 1;
    int destination = 100;
    reachHome(start, destination);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int find(long long int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 *
                find(decimal_number / 2));
}
int main () {
    string s = "0010010110101111111111111111000111101101001110110111111111111101100111011110101111111110111110111111101010110110110110111111111111101111111111111100110110111101100111111110100111111001111011111111011100111111011100011101011110111110011111100111010111111111110110111110111111000111010101001111111101001010011101101111111101100111111111011111111111101110111100100111010111111001111010111111111111101111101101111110100001011110111111110111111111011110111111011111001100110010010111";
    long long int arr;
    while ()
    int n = arr.size();
    string ans;
	for (int i = 0; i < n; i++) {
        long long int temp = find(arr[i]);
        ans += to_string(temp);
    }
    
    //step 2: compare
    if (s == ans)
        return 1;
    else 
        return 0;
    return 0;
}
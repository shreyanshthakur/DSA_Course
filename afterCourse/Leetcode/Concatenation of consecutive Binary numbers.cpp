#define MOD 1000000007
class Solution {
public:
    int numberofbits (int n) {
        return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long long int ans = 0; 
        for (int i = 1; i <= n; i++) {
            int len = numberofbits (i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};
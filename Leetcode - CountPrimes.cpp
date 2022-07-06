class Solution {
public:
    //Sieve Of Eratosthenes
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
            }
            for (int j = 2 * i; j < n; j+=i) {
                prime[j] = false; 
            }
        }
        return ans;
        
    }
};
int poweredString(int a, int b, string s){
    int i = std::stoi(s, nullptr, 2);
    if (i == 0) {
        return 0;
    }
    long long int maxi = INT_MIN, sum = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (s[j] == '1') {
                sum += a;
            }
            else {
                sum -= b;
            }
            maxi = max(maxi , sum);
        }
        sum = 0;
        maxi = max(maxi , sum);
    }
    return maxi;
    
}
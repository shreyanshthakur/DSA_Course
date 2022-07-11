bool myCheckPalindrome(string& s, int i, int j) {
    //base case
    if(i>j)
        return 1;
    if(s[i] != s[j])
        return 0;

    //recursive call
    return myCheckPalindrome(s, i+1, j-1);
}
string decimalToBinary(long long N) {
    string s;
    while (N) {
        s.push_back(N%2);
        N /= 2;
    }
    return s;
}
bool checkPalindrome(long long N)
{
	// Write your code here.
    string s = decimalToBinary(N);
    bool ans = myCheckPalindrome(s, 0, s.length() - 1);
    return ans;
}
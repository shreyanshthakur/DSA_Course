char toLowerCase (char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}
bool checkPalindrome(string s)
{
    // Write your code here.
    int st = 0;
    int e = s.length() - 1;
    while (st < e) {
        if (!isalnum(s[st])) {
            st++;
        }
        else if (!isalnum(s[e])) {
            e--;
        }
        else if (toLowerCase(s[st]) != toLowerCase(s[e])) {
            return false;
        }
        else {
            st++;
            e--;
        }
    }
    return true;
}
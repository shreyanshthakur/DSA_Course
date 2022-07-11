class Solution {
private: 
    bool valid (char ch) {
        if ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
            return 1;
        }
        else return 0;
    }
    
    char toLowerCase (char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'a' && ch <= 'z')) {
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
                if (toLowerCase(s[st]) != toLowerCase(s[e])) {
                    return false;
                }
                else {
                    st++;
                    e--;
                }
            }
            return true;
        }
public:
    bool isPalindrome(string s) {
        //remove all unnecessary 
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        return checkPalindrome(temp);
    }
};
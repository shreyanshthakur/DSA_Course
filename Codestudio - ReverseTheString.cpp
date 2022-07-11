void reverseString(string& s, int i, int j) {
    //base case
    if (i > j) {
        return;
    }
    swap(s[i++], s[j--]);

    reverseString(s, i, j);

}

string reverseString(string str)
{
	// Write your code here.
    reverseString(str, 0, str.length()-1);

    return str;
}
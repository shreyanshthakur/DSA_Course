long long int find(long long int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 *
                find(decimal_number / 2));
}

int stringConversion(string s, vector<int>&arr) {
    //step 1: convert array element to binary string
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
}

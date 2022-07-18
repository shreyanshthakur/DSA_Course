class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int ansarr[26] = {0};
        for(int i = 0; i < str.length(); i++) {
            int temp = str[i] - 'a';
            ansarr[temp]++;
        }
        int maxi = -1, ans;
        for(int i = 0; i < 26; i++) {
            if (ansarr[i] > maxi) {
                ans = i;
                maxi = ansarr[i];
            }
            
        }
        
        return 'a' + ans;
    }

};
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> v;
        int firstrow = 0, firstcol = 0, lastrow = R-1, lastcol = C-1;
        while (firstrow <= lastrow && firstcol <= lastcol) {
            for (int i = firstrow; i <= lastcol; i++) v.push_back(a[firstcol][i]);
            firstcol++;
            for (int i = firstcol; i <= lastrow; i++) v.push_back(a[i][lastcol]);
            lastcol--;
            if (firstcol <= lastrow) {
                for (int i = lastcol; i >= firstrow; i--) v.push_back(a[lastrow][i]);
                lastrow--;
            }
            if (firstrow <= lastcol) {
                for (int i = lastrow; i >= firstcol; i--) v.push_back(a[i][firstrow]);
                firstrow++;
            }
        }
        reverse (begin(v), end(v));
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
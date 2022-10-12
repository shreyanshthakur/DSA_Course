//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{

public:
    
    int get_ascii (char w, char x[], int b[],int n) {
        for (int i = 0; i < n; i++) {
            if (w == x[i]) return b[i];
        }
        return (int)w;
    }
    string maxSum(string w,char x[], int b[],int n){
        int sum = 0, max = INT_MIN, start = 0, end = 0, s = 0;
        string ans = "", res;
        for (int i = 0; i < w.length(); i++) {
        
            sum += get_ascii (w[i], x, b, n);
            if (sum > max) {
              max = sum;
              start = s;
              end = i;
            }
            if (sum < 0) {
              sum = 0;
              s = i+1;
            }
      }
      return w.substr(start, end - start + 1);
    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
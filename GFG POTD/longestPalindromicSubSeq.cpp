//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        
        string newstr = A; // reverse of string
        
        reverse(newstr.begin() , newstr.end());
        
        if(newstr == A)
            return n;
        
        int dp[n+1][n+1];
        
        // Make oth column value with zero
        for(int i = 0; i<n; i++)
            dp[i][0] = 0;
            
        // Make oth row value with zero
        for(int j = 0; j<=n; j++)
            dp[0][j] = 0;
                
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(newstr[i-1] == A[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
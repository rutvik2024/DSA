//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, int> mp;
       
        // Store occurence of each character
        for(int i = 0; i<S.length(); i++)
            mp[S[i]]++;
            
            
        // char idx = '$';
        // bool flag = true;
        // check occurence of each character
        for(int i = 0; i<S.length(); i++){
            if(mp[S[i]] == 1){
                // flag = false;
                return S[i];
            }
        }
       
        return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends
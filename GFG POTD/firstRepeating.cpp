//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string str = "";
            vector<int> frq(26, 0);
            queue<char> q;

            for(auto ch:str){
                frq[ch-'a']++; // increase frequency of each character in frq array

                if(frq[ch-'a'] == 1)
                    q.push(ch);

                while(q.size() && frq[q.front() - 'a'] > 1)
                    q.pop();

                if(q.size())
                    str += q.front();

                else    
                    str += '#';
            }

            return str;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
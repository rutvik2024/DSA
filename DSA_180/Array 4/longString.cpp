#include "bits/stdc++.h"
using namespace std;


// Time Complexity : O(2N) and Space Complexity : O(N)
int uniqueSubstrings_better(string input)
{
    map<char, int> mpp;
    int len = 0;
    int n = input.length();
    int l = 0, r = 0;

    while(r < n){
        
        while(l < r && mpp.find(input[r]) != mpp.end()){
            mpp.erase(input[l]);
            l++;
        }

        if(mpp.find(input[r]) == mpp.end()){
            len = max(len, r-l+1);
            mpp[input[r]] += 1;
            r++;
        }
    }


    return len;
}

// Time Complexity : O(N) and Space Complexity : O(N)
int uniqueSubstrings_optimal_map(string input)
{   
    int len = 0;
    int left = 0, right = 0;
    map<char, int> mpp;
    int n = input.length();


    while(right < n){
        if(mpp.find(input[right]) != mpp.end()){
            left = max(mpp[input[right]]+1, left);
        }

        
        mpp[input[right]] = right;
        len = max(len, right-left+1);
        right++;
    }

    return len;
}

int uniqueSubstrings_optimal_vec(string input)
{   
    int len = 0;
    int left = 0, right = 0;
    vector<int> mpp(256, -1);
    int n = input.length();


    while(right < n){
        if(mpp[input[right]] != -1)
            left = max(left, mpp[input[right]]+1);

        mpp[input[right]] = right;
        len = max(len, right-left+1);
        right++;
    }

    return len;
}



int main(){
    string str;
    cin>>str;

    cout<<uniqueSubstrings_optimal_vec(str)<<endl;

    return 0;
}
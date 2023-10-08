#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursive Solution
int path(int i, int j, int em, int en){
    if(i == em && j == en){
        return 1;
    }

    if(i > em || j > en)
        return 0;

    return path(i, j+1, em, en) + path(i+1, j, em, en);
}

// Approach 2: Dynamic Programming
int dyPath(int i, int j, int em, int en, vector<vector<int>> &dp){
    if(i == em && j == en){
        return 1;
    }

    if(i > em || j > en)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    else 
        return dyPath(i+1, j, em, en, dp) + dyPath(i, j+1, em, en, dp);
}

int uniquePaths(int m, int n) {
    int z = m*n;
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return dyPath(0,0,m-1, n-1, dp);
}


int main(){

    cout<<"Number of unique path : "<<uniquePaths(7,6)<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void show_vec(vector<vector <int>> &mat){
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++)
            cout<<mat[i][j]<<" ";

        cout<<endl;
    }cout<<endl;
}


vector<vector<int>> overlap_fun(vector<vector<int>> &vect){
    int n = vect.size();

    vector<vector<int>> ans;

    //1. Sort Elements
    sort(vect.begin(), vect.end()); 

    //2. Start merging

    for(int i = 0; i<n; i++){
        int start = vect[i][0];
        int end = vect[i][1];

        // If vector is not empty and vector's last element end is greater than current end then just continue it.
        if(!ans.empty() && end <= ans.back()[1])
            continue;

        // If above fails then check that current <= end
        for(int j = i+1; j<n; j++){
            if(vect[j][0] <= end)
                end = max(end, vect[j][1]);

            else   
                break;
        } 

        ans.push_back({start, end});
    }

    return ans;
}

int main()
{
    // Initializing 2D vector "vect" with
    // values
    vector<vector<int> > vect{ { 1,8 }, { 8,10}, {15,18}, {1,6}, {1,3}};

    // overlap_fun(vect);

    vector<vector<int>> ans = overlap_fun(vect);
    show_vec(ans);
    
 
    
 
    return 0;
}
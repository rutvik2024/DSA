#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = mat.size();
    int col = mat[0].size();

    int i = 0, j = col-1;

    while(i<row && j>=0){
        // Current Element is target element
        if(target == mat[i][j]) return true;

        // Current Element is Lesser than target element
        else if(mat[i][j] < target){
            i++;
        }

        // Current Element is Greater than target element
        else{
            j--;
        }
    }

    return false; 
}


int main(){
    vector<vector<int>> mat {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target;
    cin>>target;

    cout<<"True/ False: "<<searchMatrix(mat, target)<<endl;

    return 0;
}
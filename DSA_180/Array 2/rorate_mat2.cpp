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

void transpose_mat(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int current_row = 0, current_col = 0, last_row = n-1, last_col = m-1, temp;
    
    while(current_row < last_row && current_col < last_col){

        temp = mat[current_row][current_col];

        // 1. First Row traversal
        for(int j = current_col+1; (j<=last_col); j++){
            // cout<<mat[current_row][j]<<" ";
            // prev = mat[current_row][j];
            // mat[current_row][j] = temp;
            // temp = prev;
            swap(temp, mat[current_row][j]);
        }
        // cout<<endl;
        current_row++;

        // 2. Last Column traversal
        for(int i = current_row; (i<=last_row); i++){
            // cout<<mat[i][last_col]<<" ";
            // prev = mat[i][last_col];
            // mat[i][last_col] = temp;
            // temp = prev;
            swap(temp, mat[i][last_col]);
        }
        // cout<<endl;
        last_col--;

        // 3. Last Row traversal
        for(int j = last_col; (j>=current_col); j--){
            // cout<<mat[last_row][j]<<" "; 
            // prev = mat[last_row][j];
            // mat[last_row][j] = temp;
            // temp = prev;
            swap(temp, mat[last_row][j]);  
        }
        // cout<<endl;
        last_row--;

        // 4. First Column Traversal
        for(int i = last_row; (i>=current_row); i--){
            // cout<<mat[i][current_col]<<" ";
            // prev = mat[i][current_col];
            // mat[i][current_col] = temp;
            // temp = prev;
            swap(temp, mat[i][current_col]);  
        }
        // cout<<endl;
        current_col++;

        mat[current_row - 1][current_col - 1] = temp;
    }

    show_vec(mat);
    
}

int main(){
    int arr[][4] = {{1 ,2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {15,14,12,16}};
    int r = sizeof(arr)/sizeof(arr[0]);
    int c = sizeof(arr[0])/sizeof(arr[0][0]);
    // cout<<"r: "<<r<<"c: "<<c<<endl;

    vector<vector<int>> mat;

    for(int i = 0; i<r; i++){
        vector<int> temp;
        for(int j = 0; j<c; j++)
            temp.push_back(arr[i][j]);

        mat.push_back(temp);
    }

    transpose_mat(mat);

    cout<<endl;
    return 0;
}
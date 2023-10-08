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

// Brute force approach
void rotate_mat(vector<vector <int>> &mat){
    vector<vector <int>> ans;
    int r = mat.size();
    int c = mat[0].size();
    for(int i = 0; i<c; i++){
        vector<int> temp;
        for(int j = r-1; j>=0; j--){
            temp.push_back(mat[j][i]);
        }

        ans.push_back(temp);
    }

    show_vec(ans);
}

//Optimal Approach : take transpose and then take reverse of each row
void reverse_row(vector<int> &mat){
    int j = mat.size()-1;
    int i = 0;

    while(i < j){
        swap(mat[i], mat[j]);
        i++, j--;
    }
}

void transpose_mat(vector<vector<int>> &mat){
    int r = mat.size();
    int c = mat[0].size();

    for(int i = 0; i<c; i++){
        for(int j = 0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i = 0; i<r; i++){
        reverse_row(mat[i]);
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
    

    return 0;
}
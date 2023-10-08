#include<bits/stdc++.h>
using namespace std;


// Approach 1: 
void markRow(vector<vector<int>> &arr, int i, int col){
    for(int j = 0; j<col; j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &arr, int i, int row){
    for(int j = 0; j<row; j++){
        if(arr[j][i] != 0){
            arr[j][i] = -1;
        }
    }
}

void setZero(vector<vector<int>> &arr, int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(arr[i][j] == 0){
                markRow(arr, i, col);
                markCol(arr, j, row);
            }
        }
    }


    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
}


// Approach 2: 
void setZeroVec(vector<vector<int>> &arr, int row, int col){
    vector<int> rowvec (row, 0);
    vector<int> colvec (col, 0);
    
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(arr[i][j] == 0){
                rowvec[i] = 1;
                colvec[j] = 1;
            }
        }
    }

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(rowvec[i] || colvec[j]){
                arr[i][j] = 0;
            }
        }
    }

}

// Approach 3: Optimal
void setZeroOpt(vector<vector<int>> &arr, int row, int col){
    int col0 = 1;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;

                if(j != 0){
                    arr[0][j] = 0;
                }

                else{
                    col0 = 0;
                }
            }
        }
    }


    for(int i = 1; i<row; i++){
        for(int j =1; j<col; j++){
            if(arr[0][j] == 0 || arr[i][0] == 0){
                arr[i][j] = 0;
            }
        }
    }

    if(arr[0][0] == 0)
        for(int j = 0; j<col; j++)
            arr[0][j] = 0;

    if(col0 == 0)
        for(int i = 0; i<row; i++)
            arr[i][0] = 0;
}


int main(){

    // vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> arr = { {0,1,0,1}, {0,1,1,1}, {1,1,1,5}, {1,0,1,5} };
    int row = arr.size();
    int col = arr[0].size();

    // setZero(arr, row, col);
    setZeroOpt(arr, row, col);


    cout<<"Ans matrix : "<<endl;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ,";
        }cout<<endl;
    }

    return 0;
}
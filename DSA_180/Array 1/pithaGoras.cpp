#include<bits/stdc++.h>
using namespace std;


// Variation 1: Print nCr value
long long nCr(int n, int r){
    long long res = 1;
    for(int i = 0; i<r; i++){
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

// Variation 2: Print Entire row i
vector<int> rowN(int r){
    vector<int> ans;
    for(int i = 0; i<r; i++){
        int res = nCr(r-1, i);
        cout<<res<<" ";
        ans.push_back(res);
    }
    cout<<endl;
    return ans;
}

// Variation 3: Generate PithaGoras Triangle
vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans;

        for(int i = 0; i<numRows; i++){
            vector<int> temp;

            for(int j = 0; j <= i; j++){
                if(j == 0 || i == j)
                    temp.push_back(1);

                else{
                    int sum = ans[i-1][j-1] + ans[i-1][j];
                    temp.push_back(sum);
                }
            }

            ans.push_back(temp);

        }

        return ans;
}

void showVector(vector<vector<int>> &ans){
    int row = ans.size();
    for(int i = 0; i<row; i++){
        int col = ans[i].size();
        for(int j = 0; j<col; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){

    int N,R,C;
    cin>>N>>R>>C;

    if(R < C){
        cout<<"Invalid R & C value provided so Variation result can't find..!!"<<endl;
    }
    else{
        cout<<"Variation 1 result: "<<nCr(R-1,C-1)<<endl<<endl;
    }
    


    cout<<"Variation 2 result: ";
    vector<int> ans2 = rowN(R);


    cout<<endl<<"Variation 3 result: "<<endl;
    vector<vector<int>> ans = generate(N);
    showVector(ans);
    return 0;
}
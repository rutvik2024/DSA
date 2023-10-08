#include<bits/stdc++.h>
using namespace std;

void show_vec(vector<vector<int>> &arr){
    int row = arr.size();
    int col = arr[0].size();

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ,";
        }cout<<endl;
    }
}


int ClosestSum3(vector<int> &a, int X){
    int n = a.size();
    int ans = INT_MAX;
    sort(a.begin(), a.end());

    for(int i = 0; i<n-2; i++){
        int left = i+1, right = n-1;
        while(left < right){
            int sum = a[i] + a[left] + a[right];

            if(sum == X){
                return sum;
            }

            if(abs(X-sum) < abs(X-ans)){
                ans = sum;
            }

            if(sum > X){
                right--;
            }

            else
                left++;
        }

    }


    return ans;
}


int main(){
    vector<int> arr{-1, 2, 1, -4};
    int target;

    cin>>target;

    cout<<ClosestSum3(arr, target)<<endl;

    return 0;
}
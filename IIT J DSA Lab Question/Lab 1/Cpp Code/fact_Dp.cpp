#include<bits/stdc++.h>
using namespace std;


void printArr(int *arr, int n){
    for(int i = 0; i<=n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int fact_dp(int *arr, int n){
    // arr[0] = 1;
    int countMul = 0;
    for(int i = 1; i<=n; i++){
        countMul += (i-1);
        arr[i] = i*arr[i-1];
    }
    return countMul;
}


int main(){

    int n;
    cin>>n;
    int arr[n] = {1};
    int ans = fact_dp(arr, n);
    printArr(arr, n);
    cout<<"Number of multiplication operations performed: "<<ans<<endl;

    return 0;
}
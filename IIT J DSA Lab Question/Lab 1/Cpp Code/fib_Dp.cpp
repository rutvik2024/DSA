#include<bits/stdc++.h>
using namespace std;

void printArr(int *arr, int n){
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;    
}

int fib(int *arr, int n){
    arr[1] = 1;
    int add_count = 0;

    for(int i = 2; i<n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        add_count++;
    }
    
    return add_count;
}

int main(){

    int n;
    cin>>n;

    int arr[n] = {0};

    int ans = fib(arr, n);
    printArr(arr, n);
    cout<<"Number of addition operation performed: "<<ans<<endl;


    return 0;
}
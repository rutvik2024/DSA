#include<stdio.h>


void printArr(int *arr, int n){
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");    
}

int fib(int *arr, int n){
    arr[0] = 0;
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
    scanf("%d",&n);

    int arr[n];

    int ans = fib(arr, n);
    printArr(arr, n);
    printf("Number of addition operation performed: %d\n",ans);


    return 0;
}
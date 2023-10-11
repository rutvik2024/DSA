// Stack implementation using linked list and array

#include<stdio.h>


void push_stack(int *arr, int n, int *top_ptr, int val){
    (*top_ptr) = (*top_ptr) + 1;
    if(*top_ptr == n){
        printf("\nStack is full can't insert more element..\n");
        return;
    }

    arr[(*top_ptr)] = val;
    return;
}

void pop_stack(int *arr, int n, int *top_ptr){
    if(*top_ptr == -1){
        printf("\nStack is empty can't pop element..\n");
        return;
    }
    arr[(*top_ptr)] = -1;
    (*top_ptr) = (*top_ptr) - 1;
    return;
}

void display_stack(int *arr, int *top_ptr){
    if(*top_ptr == -1){
        printf("\nStack is empty can't pop element..\n");
        return;
    }

    for(int i = 0; i<=(*top_ptr); i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void main(){
   
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);

    int arr[n];
    // printf("\nEnter stack element");
    // for(int i = 0; i<n; i++)
    //     scanf("%d",&arr[i]);

    int top = -1;

    push_stack(arr, n, &top, 1);
    push_stack(arr, n, &top, 2);
    push_stack(arr, n, &top, 4);
    pop_stack(arr, n, &top);
    push_stack(arr, n, &top, 5);
    pop_stack(arr, n, &top);
    push_stack(arr, n, &top, 7);
    display_stack(arr, &top);
}
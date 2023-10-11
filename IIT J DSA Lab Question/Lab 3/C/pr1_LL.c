// #include<stdio.h>
// #include<malloc.h>


// struct node
// {
//     int data;
//     struct node* next;
// };

// typedef struct node node;

// void push(node** head, int val){
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->data = val;
//     newNode->next = (*head);
//     (*head) = newNode; 
// }



// void pop(node** head){
//     if((*head) == NULL){
//         printf("\nStack is empty..!!\n");
//         return;
//     }

//     node* next_ptr = (*head)->next;
//     free(*head);
//     (*head) = next_ptr;
// }

// // return top element
// int peep(node** head){
//     if((*head) == NULL){
//         printf("\nStack is empty..!!");
//         return -1;
//     }

//     return ((*head)->data);
// }

// void display_stack(node** head){
//     node* temp = (*head);
//     while(temp){
//         printf("%d ",temp->data);
//         temp = temp->next;
//     }
//     return;
// }

// void main(){
//     node* head = NULL;

//     int n;
//     printf("Enter number of tank: ");
//     scanf("%d",&n);


//     int arr[n];
//     printf("Enter each tank size: ");
//     for(int i = 0; i<n; i++){
//         scanf("%d",&arr[i]);
//     }

//     for(int i = 0; i<n; i++){
//         // if stack empty then directly push it.
//         if((head == NULL) || (arr[i] < 0 && head->data < 0 ) || (arr[i] > 0 && head->data > 0 ))
//             push(&head, arr[i]);

//         // else if((arr[i] < 0 && head->data < 0 ) || (arr[i] > 0 && head->data > 0 )){
//         //     push(&head, arr[i]);
//         // }
//     }

    

//     display_stack(&head);

// }

// // #include<stdio.h>

// // void main(){
// //     int n = -20;
// //     int m = -10;

// //     if(m > n)
// //         printf("True\n");

// //     else
// //         printf("False\n");




//     // for(int i = 0; i<n; i++){
//     //     if(((head) == NULL) || (arr[i] > 0 && head->data > 0) || (arr[i] < 0 && head->data < 0)){
//     //         push(&head, arr[i]);
//     //     }

//     //     // if((arr[i] > 0 && head->data > 0) || (arr[i] < 0 && head->data < 0))
//     //     //     push(&head, arr[i]);

//     //     else{
//     //         while((head) != NULL && arr[i] < 0 && head->data > 0){
//     //             // while((head) != NULL && -(arr[i]) > head->data)
//     //             //     pop(&head);

//     //             // if(-(arr[i]) < head->data){
//     //             //     push(&head, arr[i]);
//     //             //     pop(&head);
//     //             // }
//     //             int sum = arr[i] + head->data;
//     //             if(sum <= 0)
//     //                 pop(&head);
//     //         }

//     //         while((head) != NULL && arr[i] > 0 && head->data < 0){
//     //             // while((head) != NULL && -(arr[i]) < head->data)
//     //             //     pop(&head);

//     //             // if(-(arr[i]) > head->data){
//     //             //     push(&head, arr[i]);
//     //             //     pop(&head);
//     //             // }
//     //             int sum = arr[i] + head->data;
//     //             if(sum >= 0)
//     //                 pop(&head);
//     //         }
//     //     }

//     // }
// // }
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x;
}

int main() {
    int n, i, j, curr;
    scanf("%d", &n);
    int positive_tanks[n], negative_tanks[n];
    i = j = 0;
    for (int k = 0; k < n; k++) {
        scanf("%d", &curr);
        if (curr > 0) {
            positive_tanks[i++] = curr;
        } else {
            negative_tanks[j++] = curr;
        }
    }
    qsort(positive_tanks, i, sizeof(int), compare);
    qsort(negative_tanks, j, sizeof(int), compare);
    i = j = 0;
    while (i < n && j < n) {
        if (abs(negative_tanks[j]) < positive_tanks[i]) {
            j++;
        } else {
            i++;
        }
    }
    for (int k = 0; k < i; k++) {
        printf("%d ", positive_tanks[k]);
    }
    for (int k = 0; k < j; k++) {
        printf("%d ", negative_tanks[k]);
    }
    return 0;
}

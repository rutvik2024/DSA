/*
    First you have to convert  both the given decimal numbers into its  binary format and then store that binary format into a doubly linked list. After that  you have to perform binary addition on the both binary numbers and store the result into another doubly linked list. If carry is generated then you also have to create a node for it into the resultant doubly linked list.
*/

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* fptr; // Forward pointer
    struct node* bptr; // Backward pointer
};

typedef struct node node;

void insertNode(node** lis, int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;

    if((*lis) == NULL){
        (*lis) = newNode;
        newNode->fptr = NULL;
        newNode->bptr = NULL;

        return;
    }


    // Insert new node from LSB to MSB 
    newNode->fptr = (*lis);
    (*lis)->bptr = newNode;
    (*lis) = newNode;
    (*lis)->bptr = NULL;    

    return;
}

void displayList(node** lis){
    node* ptr = (*lis);
    while(ptr){
        printf("%d <--> ",ptr->data);
        ptr = ptr->fptr;
    }

    printf("\n");
    return;
}

void decimalToBinary(node** lis, int num){
    while(num){
        int dig = num%2;
        insertNode(lis, dig);
        num /= 2;
    }
    return;
}

// Get last node address
node* revPointer(node** lis){
    node* ptr = (*lis);
    if(ptr)
        while(ptr->fptr){
            ptr = ptr->fptr;
        }

    return ptr;
}


void addBinaryAddition(node** lis1, node** lis2, node** res){
    node* lastPtr1 = revPointer(lis1);
    node* lastPtr2 = revPointer(lis2);

    int carry = 0;

    if(lastPtr1 == NULL && lastPtr2 == NULL){
        insertNode(res, carry);
        return;
    }

    while(lastPtr1 != NULL && (lastPtr2 != NULL)){
        int sum = (lastPtr1-> data) + (lastPtr2->data) + carry;
        carry = sum/2;
        sum = sum%2;


        insertNode(res, sum);
        lastPtr1 = lastPtr1->bptr;
        lastPtr2 = lastPtr2->bptr;
    } 

    while(lastPtr1 != NULL){
        int sum = (lastPtr1->data) + carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
        lastPtr1 = lastPtr1->bptr;
    }

    while(lastPtr2 != NULL){
        int sum = (lastPtr2->data) + carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
        lastPtr2 = lastPtr2->bptr;
    }

    while(carry){
        int sum = carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
    }

    return;
}

void main(){
    node* lis1 = NULL; // Create list1 with empty
    node* lis2 = NULL; // Create list2 with empty
    node* res = NULL; // Create result list which contain addition
    int num1, num2;

    printf("Enter first Decimal Numeber ");
    scanf("%d",&num1);
    
    printf("Enter Second Decimal Numeber ");
    scanf("%d",&num2);


    // Convert decimal to binary
    decimalToBinary(&lis1, num1);
    decimalToBinary(&lis2, num2);


    // Print List
    displayList(&lis1);
    displayList(&lis2);

        
    // Addition of two binary number
    addBinaryAddition(&lis1, &lis2, &res);
    
    // Display Resultant List
    displayList(&res);
}
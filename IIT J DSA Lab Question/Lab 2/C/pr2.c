/*
    In this method first you have to convert a given decimal number into its  binary format. Then you have to reverse the singly linked list. After that  you have to perform the addition of the reversed singly linked list and store the result into another singly linked list. If carry is generated then you have to create a node for it into the resultant singly linked list.
*/

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

void insertNode(node** lis, int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = val;

    if((*lis) == NULL){
        (*lis) = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = (*lis);
    (*lis) = newNode;
    return ;
}


void displayList(node** lis){
    node* ptr = (*lis);
    while(ptr != NULL){
        printf("%d --> ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverseList(node** lis){
    node* prev = NULL; // Point to previous node
    node* next = NULL; // Point to next node
    node* curr = (*lis); // point to current node

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    (*lis) = prev;  
}

void decimalToBinary(node** lis, int num){
    while(num){
        int dig = num%2;
        insertNode(lis, dig);
        num /= 2;
    }
    return;
}


void addList(node** lis1, node** lis2, node** res){
    int carry = 0;
    node* ptr1 = (*lis1);
    node* ptr2 = (*lis2);

    if((ptr1) == NULL && (ptr2) == NULL){
        insertNode(res, carry);
        return;
    }

    while((ptr1) != NULL && (ptr2) != NULL){
        int sum = ((ptr1)->data) + ((ptr2)->data) + carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
        (ptr1) = (ptr1)->next;
        (ptr2) = (ptr2)->next;
    }

    while((ptr1) != NULL){
        int sum = (ptr1)->data + carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
        (ptr1) = (ptr1)->next;
    }

    while((ptr2) != NULL){
        int sum = (ptr2)->data + carry;
        carry = sum/2;
        sum = sum%2;
        
        insertNode(res, sum);
        (ptr2) = (ptr2)->next;
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
    node* lis1 = NULL;
    node* lis2 = NULL;
    node* res = NULL;

    int n1, n2;
    printf("Enter two number : ");
    scanf("%d%d",&n1, &n2);


    // Function to convert given decimal to binary
    decimalToBinary(&lis1, n1);
    decimalToBinary(&lis2, n2);

    // Printing original binary format of given decimal number
    displayList(&lis1);
    displayList(&lis2);
    
    // Addition two binary format
    addList(&lis1, &lis2, &res);

    // Reverse given list
    reverseList(&lis1);
    reverseList(&lis2);

    // Printig reverse list
    printf("Lists after reverse : \n");
    displayList(&lis1);
    displayList(&lis2);

    // Print final list
    printf("Final List After addition of reversed binary string : \n");
    displayList(&res);
}
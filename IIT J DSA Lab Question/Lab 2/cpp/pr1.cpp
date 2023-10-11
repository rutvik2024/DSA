// Create two linked list in which numbers will be store and then add both numbers and store result into another linked list. 

#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node* next;
};

void insertNode(struct node** lis, int n){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = n;

    if((*lis) == NULL){
        newNode->next = NULL;
        (*lis) = newNode;
        return;
    }

    newNode->next = (*lis);
    (*lis) = newNode;
    return ;
}


void addList(struct node** lis1, struct node** lis2, struct node** res){
    int carry = 0;

    if((*lis1) == NULL && (*lis2) == NULL){
        insertNode(res, carry);
        return;
    }

    int i = 0, j = 0;
    while((*lis1) != NULL && (*lis2) != NULL){
        int sum = ((*lis1)->data) + ((*lis2)->data) + carry;
        carry = sum/10;
        sum = sum%10;
        insertNode(res, sum);
        (*lis1) = (*lis1)->next;
        (*lis2) = (*lis2)->next;
    }

    while((*lis1) != NULL){
        int sum = (*lis1)->data + carry;
        carry = sum/10;
        sum = sum%10;
        insertNode(res, sum);
        (*lis1) = (*lis1)->next;
    }

    while((*lis2) != NULL){
        int sum = (*lis2)->data + carry;
        carry = sum/10;
        sum = sum%10;
        insertNode(res, sum);
        (*lis2) = (*lis2)->next;
    }

    while(carry){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        
        insertNode(res, sum);
    }

    return;

}



void displayNode(struct node* head){
    struct node* ptr = head;
    while(ptr){
        cout<<ptr->data<<" --> ";
        ptr = ptr->next;
    }
}




int main(){
    int arr1[] = {};
    int arr2[] = {};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    struct node* lis1 = NULL;
    struct node* lis2 = NULL;
    struct node* res = NULL;

    for(int i = 0; i<size1;i++){
        insertNode(&lis1, arr1[i]);
    }

    for(int i = 0; i<size2;i++){
        insertNode(&lis2, arr2[i]);
    }

    cout<<"Lis1 : ";
    displayNode(lis1);
    cout<<endl<<"List2 : ";
    displayNode(lis2);
    cout<<endl;
    cout<<"Result is : ";
    addList(&lis1, &lis2, &res);
    displayNode(res);
    cout<<endl;
    return 0;
}
#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* next;
};

// Inserting node in list
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

void displayList(struct node* lis){
    struct node* temp = lis;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n");
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

int revNum(int n){
    int result = 0;
    while(n){
        int dig = n%10;
        result = result*10 + dig;
        n /= 10;
    }
    return result;
}


void main(){

    struct node* lis1 = NULL;
    struct node* lis2 = NULL;
    struct node* res = NULL;

    // If number is insert through array
    // int arr1[] = {1, 2, 3, 5};
    // int arr2[] = {4, 9, 8};
    // int size1 = sizeof(arr1)/sizeof(arr1[0]);
    // int size2 = sizeof(arr2)/sizeof(arr2[0]);



    // for(int i = 0; i<size1;i++){
    //     insertNode(&lis1, arr1[i]);
    // }

    // for(int i = 0; i<size2;i++){
    //     insertNode(&lis2, arr2[i]);
    // }

    // If two interger number take as input
    int n1, n2;
    printf("Enter two number : ");
    scanf("%d%d",&n1, &n2);
    n1 = revNum(n1);
    n2 = revNum(n2);

    // Insert digit into Linked list
    while(n1){
        int dig = n1%10;
        insertNode(&lis1, dig);
        n1 /= 10;
    }

    while(n2){
        int dig = n2%10;
        insertNode(&lis2, dig);
        n2 /= 10;
    }


    printf("List1  is : ");
    displayList(lis1);
    printf("List2  is : ");
    displayList(lis2);
    addList(&lis1, &lis2, &res);
    printf("Result  is : ");
    displayList(res);
}
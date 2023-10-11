#include<stdio.h>
#include<malloc.h>
#include<math.h>

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

int revNum(int n){
    int result = 0;
    while(n){
        int dig = n%10;
        result = result*10 + dig;
        n /= 10;
    }
    return result;
}

int binaryToDecimal(struct node** lis){
    int i = 0;
    int decNum = 0;
    while((*lis) != NULL){
        int idx = 1<<i;
        decNum += (((*lis)->data) * idx);
        i++;
        (*lis) = (*lis)->next;
    }

    return decNum;
}

void decimalToBinary(struct node** res, int n){
    if(n == 0){
        insertNode(res,n);
        return ;
    }

    while(n){
        int dig = n%2;
        insertNode(res,dig);
        n /= 2;
    }
}

void main(){
    struct node* lis1 = NULL;
    struct node* res = NULL;
    int n;
    int arr1[] = {1,0,1,0,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);


    for(int i = 0; i<size1;i++){
        insertNode(&lis1, arr1[i]);
    }

    // printf("Enter number in binary format(0,1) : ");
    // scanf("%d",&n);
    // n = revNum(n);
    // while(n){
    //     int dig = n%10;
    //     insertNode(&lis1, dig);
    //     n /= 10;
    // }

    int ans = binaryToDecimal(&lis1);
    printf("given binary number decimal is : %d\n",ans);

    int revAns = revNum(ans);
    printf("Reverse of %d is %d",ans,revAns);

    decimalToBinary(&res, revAns);
    printf("\nFinal Binary of %d : ",revAns);
    displayList(res);


    // printf("Decimal is : %d\n",ans);

}
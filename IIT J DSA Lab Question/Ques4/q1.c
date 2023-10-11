#include<stdio.h>
#include<stdlib.h>


int is_Stack_Full(int *top, int size){
    if(*top == size)
        return 1;

    return 0;
}

int is_Stack_Empty(int *top){
    if((*top) == -1)
        return 1;
    return 0;
}

void push(int* stack, int val, int* top, int size){
    if(is_Stack_Full(top, size)){
        printf("\nStack is full can't insert new item\n");
        return;
    }
    // if stack is not full then insert value at top element
    stack[++(*top)] = val;
    return;
}

int pop(int* stack, int *top){
    if(is_Stack_Empty(top)){
        printf("\nStack is Empty can't pop item\n");
        return -1;
    }
    int item = stack[(*top)];
    *top -= 1;
    return item;
}

void display_Stack(int* stack, int *top){
    int n = (*top);
    if(is_Stack_Empty(top)){
        printf("\nStack is Empty can't pop item\n");
        return;
    }
    for(int i = 0; i<=n; i++){
        printf("%d, ",stack[i]);
    }printf("\n");
    return;
}


// Queue Implementaion Using Array
int is_Queue_Full(int *front, int *rear, int size){
    if(*front == ((*rear) + 1)%size){
        return 1;
    }
    return 0;
}

int is_Queue_Empty(int *front, int *rear){
    if((*front) == (*rear) && (*front == -1)){
        return 1;
    }
    return 0;
}

// Done from rear end
void enQueue(int *que, int *rear, int* front, int size, int val){
    
    // If Queue is Empty
    if(is_Queue_Full(front, rear, size)){
        printf("\nQueue is Full\n");
        return;
    }

    // If first insertion happen
    if((*front) == (*rear) && (*front == -1)){
        (*rear)++;
        (*front)++;
        que[(*rear)] = val;
        return;
    }

    // If it is not first insertion then
    que[++(*rear)] = val;
    return;
}

// Done from front
int deQueue(int *que, int *rear, int* front, int size){
    
    // Queue is Empty then can't perform deletion
    if(is_Queue_Empty(front, rear)){
        printf("\nQueue is Empty\n");
        return -1;
    }

    // If queue is not empty
    int item = que[(*front)];
    
    // If this is last deletion then we have to update front and rear to -1
    if((*front) == (*rear)){
        (*front) = (*rear) = -1;
        return item;
    }
    (*front)++;

    return item;
}


// Display Queue element from front to rear
void display_Queue(int *que, int *front, int *rear){
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    // Queue is Empty then can't perform deletion
    if(is_Queue_Empty(front, rear)){
        printf("\nQueue is Empty\n");
        return;
    }

    for(int i = (*front); i != (*rear)+1; i++){
        printf("%d ",que[i]);
    }
    printf("\n");


    return;
}


void main(){

    int size = 5;
    int arr[10000];
    printf("Enter Number of element:");
    scanf("%d",&size);

    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    int mid = size/2;
    int rear = -1, front = -1;
    int que[10000];
    int stack[10000];


    int top = -1;
    int item;


    for(int i = 0; i<mid; i++){
        push(stack, arr[i], &top, size);
    }

    // Insert Element in queue
    // 1. Insert Stack element
    while(!(is_Stack_Empty(&top))){
        int item = pop(stack, &top);
        enQueue(que, &rear, &front, size, item);
    }

    // 2. Insert element from array
    for(int i = mid; i<size; i++){
        enQueue(que, &rear, &front, size, arr[i]);
    }

    display_Queue(que, &front, &rear);
    


}
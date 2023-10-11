#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int count=0;

struct queue
{
    int n;
    int front;
    int rear;
    int* arr;
};
 
 
int queue_isEmpty(struct queue *q){
    if(q->rear==q->front && q->rear == -1){
        return 1;
    }
    return 0;
}
 
int queue_isFull(struct queue *q){
    if(q->rear==q->n-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int ID){
    if(queue_isFull(q)){
        //printf("This Queue is full\n");
        return;
    }
    if(q->rear == q->front && q->rear == -1){
        q->rear++;
        q->front++;
        q->arr[q->rear] = ID;
        printf("Enqued element: %d\n", ID);
        return;
    }
    else{
        q->rear++;
        q->arr[q->rear] = ID;
        printf("Enqued element: %d\n", ID);
        return;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(queue_isEmpty(q)){
        //printf("This Queue is empty\n");
        return 0;
    }

    // If only one element is there is queue
    if(q->front == q->rear){
        a = q->arr[q->front]; 
        q->front = -1;
        q->rear = -1;
        return a;
    }
    else{
        a = q->arr[q->front]; 
        q->front++;
    }
    return a;
}
 
// Display Queue element

// Display Queue element from front to rear
void displayQueue(struct queue *que){
    // Queue is Empty then can't perform deletion
    if(queue_isEmpty(que)){
        printf("\nQueue is Empty\n");
        return;
    }

    for(int i = que->front; i != que->rear+1; i++){
        printf("%d ",que->arr[i]);
    }
    printf("\n");


    return;
}

//storing elements in stack

/*struct stack{
    int size;
    int top;
    int *arr;
};

int struct_isEmpty(struct stack* s){
    if(s->top == -1){
      return 1;  
    }else{
        return 0;
    }
};

int struct_isFull(struct stack* s){
    if (s->top >= s->size-1){
       return 1; 
    }else{
        return 0;
    }
}

void push(struct stack *s, int ID){
    if(struct_isFull(s)){
       // printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        s->top++;
        s->arr[s->top] = ID;
    }
}

int pop(struct stack* s){
    if(struct_isEmpty(s)){
        //printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int ID = s->arr[s->top];
        s->top--;
        return ID;
    }
}*/

struct Stack {			//creating a stack using arrays
	int top;
	unsigned capacity;
	int* arr;
};

struct Stack* createStack(unsigned capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

//%%%%%%%%%%%%%%%%%%%%%
//stack functions

int isEmpty(struct Stack* stack){	
	return stack->top == -1;
	}


void push(struct Stack* stack, int tank){
	stack->arr[++stack->top] = tank;
	}

int pop(struct Stack* stack){
	if (isEmpty(stack)){
		return INT_MIN;}
	//printf("%d blam blam, youve been popped")
	return stack->arr[stack->top--];
	}

int top(struct Stack* stack){		//Finding the topmost element in the stack
	if (isEmpty(stack)){
		return INT_MIN;}
	return stack->arr[stack->top];
	}

int main(){

    struct queue q; 
    int n, i, ID;       // n is size of queue, i is used for traversing, ID is value which want to insert
    //q.front = q.rear = 0;  // needs to initialize with -1 because you are using pre-increment to enque element and index 0 is also use in queue

    q.front = -1;
    q.rear = -1;

    scanf("%d",&n);
    q.n = n;
    q.arr = (int*)malloc(q.n*sizeof(int));

    int temp_arr[n];
    // scanf("%d", &n); This line needs to shift to above q.arr                 //size od queue
    
    
    for (i = 0; i<n; i++){
        // scanf("%d", &ID);
        // enqueue(&q, ID);
        scanf("%d",&temp_arr[i]);
    }
    

    struct Stack *sp;
    sp = createStack(n);

    // Here we have to push element into stack upto n/2 so first we deque element from queue till n/2 and 
    for (i = 0; i<n/2; i++){
        // ID = dequeue(&q);
        push(sp, temp_arr[i]);
        // printf("%d ", pop(sp));
    }    

    // After push n/2 element into stack we pop element from stack and then enqueue that element into queue.

    for(i = 0; i<n/2; i++){
        int item = pop(sp);
        enqueue(&q, item);
    }

    for(;i<n; i++){
        enqueue(&q, temp_arr[i]);
    }
    
    printf("Display Queue element : \n");
    displayQueue(&q);
    printf("-------------------------------------\n");
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// structure to store the values in deque
struct deque {
    int front, rear, size;
    int capacity;
    int *array;
};

// function to create a deque of given capacity
struct deque* createDeque(int capacity)
{
    struct deque* deq = (struct deque*)malloc(sizeof(struct deque));
    deq->front = 0;
    deq->rear = capacity - 1;
    deq->size = 0;
    deq->capacity = capacity;
    deq->array = (int*)malloc(deq->capacity * sizeof(int));
    return deq;
}

// function to check if deque is full
bool isFull(struct deque* deq)
{
    return (deq->size == deq->capacity);
}

// function to check if deque is empty
bool isEmpty(struct deque* deq)
{
    return (deq->size == 0);
}

// function to insert elements at the rear of the deque
void insertRear(struct deque* deq, int item)
{
    if (isFull(deq))
        return;
    deq->rear = (deq->rear + 1) % deq->capacity;
    deq->array[deq->rear] = item;
    deq->size = deq->size + 1;
}

// function to delete elements from the front of the deque
void deleteFront(struct deque* deq)
{
    if (isEmpty(deq))
        return;
    deq->front = (deq->front + 1) % deq->capacity;
    deq->size = deq->size - 1;
}

// function to find the maximum stock price for each k-day period
int stockPrice(int price[], int n, int k)
{
    int max_sum = 0;
    struct deque* deq = createDeque(k);
    int i;
    // for (i = 0; i < k; i++) {
    //     while ((!isEmpty(deq)) && price[deq->array[deq->rear]] <= price[i])
    //         deleteFront(deq);
    //     insertRear(deq, i);
    // }
    // for ( ; i < n; i++) {
    //     max_sum += price[deq->array[deq->front]];
    //     while ((!isEmpty(deq)) && deq->array[deq->front] <= i - k)
    //         deleteFront(deq);
    //     while ((!isEmpty(deq)) && price[deq->array[deq->rear]] <= price[i])
    //         deleteFront(deq);
    //     insertRear(deq, i);
    // }
    // max_sum += price[deq->array[deq->front]];
    // return max_sum;


    // Modify the code by me.
    for(i = 0; i < n - k + 1; i++){
        int max = price[i];
        for(int j = i+1; j <k+i; j++){
            if(max < price[j])
                max = price[j];
        }
        // printf("Max is : %d\n",max);
        max_sum += max;
        insertRear(deq, max);
    }
    printf("\n");

    return max_sum;
}

// main function
int main()
{

    // struct deque *deq;

    // deq = createDeque()
    int n, k, i, price;
    scanf("%d", &n);                  //no. of stocks
    scanf("\n%d", &k);              //value of k
    int max[n];
    for (i = 0; i<n; i++){
        scanf("%d", &max[i]);
        // insertRear(&deq, price);
    }
    printf("\n--------------------------------------------------------\n");
    printf("%d", stockPrice(max, n, k));
    return 0;
}
  

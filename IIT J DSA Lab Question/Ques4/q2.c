// Deque implementation in C

#include <stdio.h>


int count(int *arr, int MAX) {
  int c = 0, i;

  for (i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}

void addFront(int *arr, int item, int *pfront, int *prear, int MAX) {
  int i, k, c;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if (*pfront == -1) {
    *pfront = *prear = 0;
    arr[*pfront] = item;
    return;
  }

  if (*prear != MAX - 1) {
    c = count(arr, MAX);
    k = *prear + 1;
    for (i = 1; i <= c; i++) {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    *pfront = k;
    (*prear)++;
  } else {
    (*pfront)--;
    arr[*pfront] = item;
  }
}


void addRear(int *arr, int item, int *pfront, int *prear, int MAX) {
  int i, k;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if (*pfront == -1) {
    *prear = *pfront = 0;
    arr[*prear] = item;
    return;
  }

  if (*prear == MAX - 1) {
    k = *pfront - 1;
    for (i = *pfront - 1; i < *prear; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    (*prear)--;
    (*pfront)--;
  }
  (*prear)++;
  arr[*prear] = item;
}

int delFront(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*pfront];
  arr[*pfront] = 0;

  if (*pfront == *prear)
    *pfront = *prear = -1;
  else
    (*pfront)++;

  return item;
}

int delRear(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*prear];
  arr[*prear] = 0;
  (*prear)--;
  if (*prear == -1)
    *pfront = -1;
  return item;
}


void display(int *arr, int *front, int *rear) {
    for(int i = (*front); i != (*rear)+1; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int sumQueue(int *arr, int *front, int *rear){
    int ans = 0;
    for(int i = (*front); i != (*rear)+1; i++){
        ans += arr[i];
        printf("----\n");
    }

    return ans;
}

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];
    int countZ = 0;
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
        countZ++;
    }
    printf("-----------------------------------------------------\nCount is : %d\n-------------------------------------------------------\n",countZ);
    int k;
    scanf("%d", &k);
    int front = -1, rear = -1;
    int z = size - k + 1;
    int queue[z];

    for(int i = 0; i<z; i++){
        int max = arr[i];
        for(int j = i+1; j <k+i; j++){
            if(max < arr[j])
                max = arr[j];
        }
        printf("Max is : %d\n",max);
        addRear(queue, max, &front, &rear, size);
    }
    // display(queue, &front, &rear);
    printf("Sum is : %d\n",sumQueue(queue, &front, &rear));

}




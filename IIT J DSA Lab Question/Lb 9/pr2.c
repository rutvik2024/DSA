// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
	int i, j,count = 0;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                count++;
            }
        }

    return count;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
    int n;
    scanf("%d", &n);
	int arr[n];
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }

	int res = bubbleSort(arr, n);
    printf("swap: %d",res);

	// printf("Sorted array: \n");
	// printArray(arr, n);
	return 0;
}

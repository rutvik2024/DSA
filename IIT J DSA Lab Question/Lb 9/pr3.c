#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
//function to display array
void display(char array[][2][1000], int n){
  for(int i=0; i<n; i++){
    for(int j = 0; j<2; j++){
        printf("%s, ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// void linearSearch(char (*str)[2][1000], char *key, int n){
//     int fount = 0;
//     for(int i=0; i<n; i++){
//         if(strcmp(str[i][1], key) == 0){
//             printf("Element Present at : %d\n",i);
//             fount = 1;
//         }
//     }
//     if(fount == 0){
//         printf("Element is not present\n");
//     }
// }
 
int binarySearch(char (*str)[2][1000], char *s1, int low, int high){
    int found = 0;
    int mid = low + (high-low)/2;

    while(low <= high){
        if(strcmp(str[mid][0], s1) == 0){
            // printf("key found at the position %d\n",mid+1);
            return mid;
        }

        else if(strcmp(str[mid][0], s1) < 0){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }

        mid = low + (high-low)/2;
    }

    return -1;
}


int getPivot(char (*str)[2][1000], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(str[mid][0] >= str[0][0])
            s = mid+1;

        else
            e = mid;

        mid = s + (e-s)/2;
    }

    return s;
}


int main()
{
  int n;
  scanf("%d",&n);
  //create an array of strings
  char array[n][2][1000];

  //Inputting names
  printf("Enter %d Strings: \n", n);
  for(int i=0; i<n; i++){
    for(int j = 0; j<2; j++){
        scanf("%s", array[i][j]);
    }
  }

  //display the original array
  printf("Original array: ");
  display(array, n);

  char temp[1000];

  //Sort array using the Buuble Sort algorithm
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1-i; j++){
      if(strcmp(array[j][0], array[j+1][0]) > 0){
        //swap array[j] and array[j+1]
        strcpy(temp, array[j][0]);
        strcpy(array[j][0], array[j+1][0]);
        strcpy(array[j+1][0], temp);

        strcpy(temp, array[j][1]);
        strcpy(array[j][1], array[j+1][1]);
        strcpy(array[j+1][1], temp);

      }
    }
  }

  //display the sorted array
  printf("Sorted Array: ");
  display(array, n);

  char key[1000];
  printf("Enter a string to search: ");
  scanf("%s", key);

  //  linearSearch(array, key, n);
    
    int pivot = getPivot(array, n);
    int l1 = binarySearch(array, key, 0, pivot);
    int l2 = binarySearch(array, key, pivot+1, n-1);

    if(l1 == -1 && l2 == -1){
      printf("Element not present");
    }

    else if(l1 != -1 && l2 == -1){
      int idx = (l1 - pivot) % n;
      printf("key found at the position %d\n",idx);
      

    }
    else{
      int idx = (l2 - pivot) % n;
      printf("key found at the position %d\n",idx);
    }
 

  return 0;
}

// Smith John

// Taylor Mary

// Williams Mark

// Allen David

// Brown Sarah

// Clark James

// Davis Andrew

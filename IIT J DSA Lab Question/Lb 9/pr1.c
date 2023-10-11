#include<stdio.h>
#include<string.h>

void uperToLower(char *s1){
    int len = strlen(s1);
    for(int i = 0; i<len; i++){
        if(s1[i] >= 'A'  && s1[i] <= 'Z'){
            s1[i] += 32;
        }
    }
}

int binarySearch(char (*str)[1000], char *s1, int low, int high){
    int found = 0;
    int mid = low + (high-low)/2;

    while(low <= high){
        if(strcmp(str[mid], s1) == 0){
            printf("key found at the position %d\n",mid+1);
            return mid;
        }

        else if(strcmp(str[mid], s1) < 0){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }

        mid = low + (high-low)/2;
    }

    return -1;
}


void main(){
    // Array of string
    int n, low, high, mid, found = 0;


    printf("Enter how many string (names): ");
    scanf("%d", &n);
    char str[n][1000], s1[1000];

    printf("Enter %d strings:\n", n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", str[i]);
    }

    printf("Enter a string to search: ");
    scanf("%s", s1);

    low = 0; 
    high = n-1;

    // mid = low + (high-low)/2;

    // while(low <= high){
    //     if(strcmp(str[mid], s1) == 0){
    //         printf("key found at the position %d\n",mid+1);
    //         found = 1;
    //         break;
    //     }

    //     else if(strcmp(str[mid], s1) < 0){
    //         low = mid + 1;
    //     }

    //     else{
    //         high = mid - 1;
    //     }
    // }

    // if(found == 0){
    //     printf("Element is not present..\n");
    // }

    if(binarySearch(str, s1, low, high) == -1){
        printf("Element is not present..\n");
    }
}   
#include<stdio.h>


int fib(int n, int i){
    static int number_Add = 0;
    if(n == 0 || n == 1){
        return n;
    }
    number_Add++;
    int ans = fib(n-1,i) + fib(n-2,i);
    if(i == n)
        printf("Addtion is : %d\n",number_Add);
    return ans;
}


int main(){
    int n;
    scanf("%d", &n);

    printf("%d",fib(n,n));
}
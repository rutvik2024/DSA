#include<bits/stdc++.h>
using namespace std;



int fib(int n){
    static int number_Add = 0;
    static int flag = n;
    if(n == 0 || n == 1){
        return n;
    }
    number_Add++;
    int ans = fib(n-1) + fib(n-2);
    if(flag == n)
        cout<<"\nAddtion is : "<<number_Add<<endl;
    return ans;
}


int main(){
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
}
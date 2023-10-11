/*
    In this part, write a recursive program, that will take the number n as an input from the user, and then outputs all the factorials of numbers from 0…n in a single line as space-separated integers. 
    Apart from this, you also have to output the number of multiplication operations that your program has to perform in order to complete the above task of printing all the factorials. This will be helpful in comparing the two methods that we are going to use in this lab. Print the number of multiplication operations in the next line as a single integer after printing the string “Number of multiplication operations performed: “.
*/

#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    static int countMul = 0;
    static int flag = 0;
    flag++;
    if(n == 0){
        // cout<<"Factorial of "<<n<<" is : "<<1<<endl;
        cout<<1<<" ";
        return 1;
    }

    countMul += (n-1);
    int ans = n*fact(n-1);
    // cout<<"Factorial of "<<n<<" is : "<<ans<<endl;
    cout<<ans<<" "; 
    if(flag-1 ==  n)
        cout<<"\nNumber of multiplication operations performed: "<<countMul<<endl;
    return ans;
}


int main(){

    int n;
    cin>>n;

    fact(n);

    cout<<endl;

    return 0;
}
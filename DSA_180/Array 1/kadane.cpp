#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int *a, int n){
    int max_f = INT_MIN;
    int max_end = 0;
    int start = 0;
    int end = 0;

    for(int i = 0; i<n; i++){
        max_end += a[i];
        if(max_f < max_end){
            max_f = max_end;
            end = i;
        }

        if(max_end < 0){
            max_end = 0;
            start = i+1;
        }

    }

    cout<<"Start: "<<start<<" & end: "<<end<<endl;
    return max_f;
}


int main(){
    int a[] = {-7 ,-8 ,-16 ,-4 ,-8 ,-5 ,-7 ,-11 ,-10 ,-12 ,-4 ,-6 ,-4 ,-16 ,-10 };
    int n = sizeof(a) / sizeof(a[0]);

    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    return 0;
}



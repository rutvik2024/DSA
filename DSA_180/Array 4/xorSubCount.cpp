#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2N) and Space Complexity : O(N)
int subarraysWithSumK_optimal(vector < int > a, int b) {
    int count = 0;
    int xorSum = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int n = a.size();

    for(int i=0; i<n; i++){
        xorSum ^= a[i];
        int rem = xorSum^b;
        count += mpp[rem];
        mpp[xorSum] += 1;
    }

    return count;
}



int main(){
    vector<int> a = {1, 2, 3, 2};
    long long k;
    cin>>k;

    cout<<"Ans is :"<<subarraysWithSumK_optimal(a,k)<<endl;


    return 0;
}
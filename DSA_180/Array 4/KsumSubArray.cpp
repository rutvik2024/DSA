#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(NLogN) Space complexity : O(N)
int findAllSubarraysWithGivenSum_optim_1(vector<int> &arr, int k){
    int count = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int prefSum = 0;
    int n = arr.size();

    for(int i = 0; i<n; i++){
        prefSum += arr[i];
        int rem = prefSum - k;
        count += mpp[rem];
        mpp[prefSum] += 1;
    }

    return count;
}


// Time Complexity : O(NlogN) Space complexity : O(1)
int findAllSubarraysWithGivenSum_optim_2(vector < int > & arr, int k){
    int count = 0;
    int l = 0, r = 0;
    int n = arr.size();
    int sum = arr[0];

    while(r < n){
        while(l < r && sum > k){
            sum -= arr[l];
            l++;
        }

        if(sum == k)
            count++;

        r++;
        if(r < n)
            sum += arr[r];
    }

    return count;
}


int main(){
    vector<int> a = {1, 2, 3, 1, 1, 1, 1};
    long long k;
    cin>>k;

    cout<<"Ans is :"<<findAllSubarraysWithGivenSum_optim_1(a,k)<<endl;

    return 0;
}
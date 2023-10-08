#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using two for loop check one by one each element
// Time Complexity : O(n^2) space Complexity : O(1)
int findMajorityElement_brute(int arr[], int n) {
	for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[i] == arr[j])
                count++;
        }

        if(count > n/2){
            return arr[i];
        }
    }

    return -1;
}


// Approach 2: Store each element occurence and then check whatever element occurence is more than n/2 will be our ans
// Time Complexity : O(nlogn + n) space Complexity : O(n)
// Here we are using ordered map that's why time comlexity is O(nlogn + n) but if we use unordered map then it will be o(n + n)
int findMajorityElement_better(int arr[], int n) {
    // unordered_map<int, int> m;
    map<int, int> m;
    for(int i = 0; i<n; i++)
        m[arr[i]]++;

	for(auto it: m){
        if(it.second > (n/2))
            return it.first;
    }

    return -1;
}

// Approach 3: Using Moore's Voting method
// Time Complexity : O(n) space Complexity : O(1)
int findMajorityElement_optimal(int arr[], int n) {
    // Appying Moore's vating method
    int count = 0;
    int elem;

    for(int i = 0; i<n; i++){
        if(count == 0){
            count = 1;
            elem = arr[i];
        }

        else if(elem == arr[i])
            count++;

        else{
            count--;
        }
    }

    // Check the voted elem is majority or not.
    int cnt = 0;
    for(int i = 0; i<n; i++)
        if(arr[i] == elem)
            cnt++;
    
    if(cnt > n/2)
        return elem;

    return -1;
}


int main(){
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = findMajorityElement_better(arr, n);


    cout<<"Element is : "<<ans<<endl;

    return 0;
}
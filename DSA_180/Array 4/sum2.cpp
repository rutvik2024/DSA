#include<bits/stdc++.h>
using namespace std;

// Approach 1: Naive Brute force 2 for loop
// Time complexity : O(N^2) and Space complexity : O(1)

// Approach 2: Using Hash Map 
// Time complexity : O(N) and Space complexity : O(N)

// Variant 1 : Return Yes or No
string sum2_map_v1(vector<int> &a, int target){
    unordered_map<int, int> mp;

    int n = a.size();
    for(int i = 0; i<n; i++){
        int elem = target - a[i];
        if(mp.find(elem) != mp.end()){
            return "Yes";
        }

        mp[a[i]] = i;
    }

    return "No";
}

// Variant 2: Return indices of element
vector<int> sum2_map_v2(vector<int> &a, int target){
    unordered_map<int, int> mp;
    int n = a.size();

    for(int i = 0; i<n; i++){
        int elem = target - a[i];

        if(mp.find(elem) != mp.end())
            return {mp[elem], i};

        mp[a[i]] = i;
    }

    return {-1, -1};
}

// Approach 3: Sort array first then using two pointer method do this.
// Time complexity : O(N + NlogN) and Space complexity : O(1)


int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target;
    cin>>target;

    vector<int> ans = sum2_map_v2(arr, target);
    cout<<"Target is : "<<ans[0]<<" ,"<<ans[1]<<endl;

    return 0;
}
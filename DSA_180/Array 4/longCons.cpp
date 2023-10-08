#include<bits/stdc++.h>
using namespace std;


// Approach by me
// time complexity : O(nlogn + n) space complexity: O(1)
int longSec_by_me(vector<int> &arr){
    // If given vector is empty
    if(arr.empty())
        return 0;


    int n = arr.size();

    int ans = 1;
    int prev = 1;


    // If there is one element return 1
    if(n == 1) return 1;

    // For more then 1 element

        // 1. Sort array 
        sort(arr.begin(), arr.end());

        // 2. traverse on vector
        for(int i = 0; i<n-1 ; i++){

            // if current and next element has diff 1 then inc prev and change ans with max of prev and ans
            if(arr[i] - arr[i+1] == -1){
                prev++;
                ans = max(ans, prev);
            }

            // if current and next element are same then do nothing
            else if(arr[i] == arr[i+1])
                continue;

            // If not then change prev with 1
            else
                prev = 1;
        }


    return ans;
}


// Approach 1: Using hashmap
// time complexity : O(n) space complexity: O(1)

int longSec_optim(vector<int> &arr){
    int ans = 0;
    set<int> hashset;

    for(int n: arr)
        hashset.insert(n);

    for(int n: arr){
        if(!hashset.count(n-1)){
            int curr_n = n;
            int prev = 1;

            while(hashset.count(curr_n+1)){
                curr_n = curr_n+1;
                prev++;
            }

            ans = max(ans, prev);
        }
    }

    return ans;
}


int main(){
    vector<int> arr = { 0};
    int ans = longSec_optim(arr);
    cout<<"Longest Sequence is : "<<ans<<endl;

    return 0;
}
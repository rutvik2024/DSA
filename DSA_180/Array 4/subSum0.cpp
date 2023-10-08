#include<bits/stdc++.h>
using namespace std;

// Approach by me
// Time complexity : O(n^2) and Space complexity: O(1)
int LongestSubsetWithZeroSum_me(vector < int > &arr){
    int count = 0;
    int prev_count = 0;
    int n = arr.size();

    for(int i = 0; i<n; i++){

        // If sub array length is smaller than the count then no need to check because we already get longest subarray
        if(n-i < count) 
            break;
        
        
        long long sum = arr[i];
        if(sum == 0){
            prev_count = 1;
            count = max(count, prev_count);
        }


        for(int j = i; j<n;j++){
            if(j == i){
                continue;
            } 

            sum += arr[j];
            if(sum == 0){
                prev_count = j-i+1;
                count = max(count, prev_count);
                cout<<"Count for "<<arr[i]<<" and "<<arr[j]<<" is : "<<count<<endl;
            }
        }
    }
    return count;
}


// Approach by Optimal
// Time complexity : O(nlogn) and Space complexity: O(n)
int LongestSubsetWithZeroSum_optim(vector < int > &arr){
    unordered_map<int, int> mp; // We store sum as a key and index as a value
    int ans = 0;
    int sum = 0;
    int n = arr.size();

    mp[0] = -1; 

    for(int i = 0; i<n; i++){
        sum += arr[i];

        // If the sum is in the given map then we calculate current_index- first_sum_occurence_index
        if(mp.find(sum) != mp.end()){
            ans = max(ans, i-mp[sum]);
        }

        else{
            mp[sum] = i;
        }
    }

    return ans;
}


int main(){
    vector<int> arr{0, 0, 0};
    int ans = LongestSubsetWithZeroSum_optim(arr);

    cout<<"Ans is : "<<ans<<endl;

    return 0;
}
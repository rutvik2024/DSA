#include<bits/stdc++.h>
using namespace std;



// Approach by Brute by me
// Time complexity : O(n^2) and Space complexity: O(1)
int longestSubarrayWithSumK_brute(vector<int> a, long long k) {
    int ans = 0;
    int n = a.size();

    if(n == 0)
        return ans;
    
    for(int i = 0; i<n; i++){
        if(n-i < ans)
            break;
        
        long long sum = 0;

        for(int j = i; j<n; j++){
            // if(i==j) continue;

            sum += a[j];
            if(sum == k)
                ans = max(ans, j-i+1);

            if(sum > k)
                break;

        }
    }


    return ans;
}


// Approach by better
// Time complexity : O(nlogn) and Space complexity: O(n)
int longestSubarrayWithSumK_better(vector<int> a, long long k) {
    int ans = 0;
    unordered_map<long long, int> mp;
    int n = a.size();
    long long sum = 0;

    for(int i = 0; i<n; i++){
        sum += a[i];

        if(sum == k){
            ans = max(ans, i+1);
        }

        long long rem = sum-k;
        if(mp.find(rem) != mp.end()){
            int len = i-mp[rem];
            ans = max(ans, len);
        }

        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }


    return ans;
}


// Approach by Optimal
// Time complexity : O(nlogn) and Space complexity: O(1)
int longestSubarrayWithSumK_optimal(vector<int> a, long long k) {
    int ans = 0;
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];

    while(right < n){
        while(right < n && sum > k){
            sum -= a[left];
            left++;
        }

        if(sum == k)
            ans = max(ans, right-left+1);

        right++;
        if(right < n)
            sum += a[right];
    }

    return ans;
}



int main(){
    vector<int> a = {1, 2, 3, 1, 1, 1, 1};
    long long k;
    cin>>k;

    cout<<"Ans is :"<<longestSubarrayWithSumK_optimal(a,k)<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void next_per(vector<int> &nums){
    int n = nums.size();
    int idx = -1;

    // Find break point
    for(int i = n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            idx = i;
            break;
        }
    }

    // If no break point found
    if(idx == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n-1; i>= idx; i--){
        if(nums[i] > nums[idx]){
            swap(nums[i], nums[idx]);
            break;
        }
    }

    reverse(nums.begin() + idx + 1, nums.end());

    return;
}




int main(){

    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;

    for(int i = 0; i<size; i++)
        nums.push_back(arr[i]);

    next_per(nums);

    for(int i = 0; i<size; i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
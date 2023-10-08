// Sort 0,1,2
#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &nums){
    int l = 0, m = 0, h = nums.size()-1;

    while(m <= h){
        if(nums[m] == 0)
            swap(nums[l++], nums[m++]);

        else if(nums[m] == 1)
            m++;

        else if(nums[m] == 2)
            swap(nums[m], nums[h--]);
    }
    return;
}


int main(){

    int arr[] = {2,0,2,1,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;

    for(int i = 0; i<size; i++)
        nums.push_back(arr[i]);

    sort012(nums);

    for(int i = 0; i<size; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    
    return 0;
}
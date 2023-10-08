#include<bits/stdc++.h>
using namespace std;

void stock(vector<int> &nums){
    int min = nums[0];
    int pr = 0;
    int n = nums.size();
    for(int i = 1; i<n; i++){
        if(min > nums[i])
            min = nums[i];

        int z = nums[i] - min;

        if(z < 0){
            pr = 0;
        }

        else if(z > pr){
            pr = z;
        }
    }


    cout<<pr<<endl;
}


int main(){

    int arr[] = {7,6,4,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;

    for(int i = 0; i<size; i++)
        nums.push_back(arr[i]);

    stock(nums);

    for(int i = 0; i<size; i++)
        cout<<nums[i]<<" ";
    cout<<endl;


    return 0;
}
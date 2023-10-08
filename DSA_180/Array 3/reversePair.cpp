#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }

        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low; i<=high; i++){
        a[i] = temp[i-low];
    }

}

int countPairs(vector<int> &a, int low, int mid, int high){
    int count = 0;
    int right = mid+1;

    for(int i = low; i<=mid; i++){
        while(right <= high && a[i] > 2*a[right])
            right++;

        count += right - (mid + 1);
    }

    return count;
}



int merge_sort(vector<int> &a, int low, int high){
    int count = 0;
    if(low >= high) return count;

    int mid = low + (high - low)/2;
    count += merge_sort(a, low, mid);
    count += merge_sort(a, mid+1, high);
    count += countPairs(a, low, mid, high);
    merge(a, low, mid, high);

    return count;
}

int team(vector <int> & skill, int n)
{
    return merge_sort(skill, 0, n-1);
}


int main(){

    vector<int> a{4 ,1, 2, 3, 1};
    int low = 0;
    int high = a.size();
    cout<<"Number of inversion : "<<team(a, high)<<endl;

    return 0;
}
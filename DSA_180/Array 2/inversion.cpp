#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int count = 0;

    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }

        else{
            count += mid - left + 1;
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

    return count;   
}



int merge_sort(vector<int>&a, int low, int high){
    int count = 0;
    if(low >= high) return count;

    
    int mid = (low + high)/2;
    count += merge_sort(a, low, mid);
    count += merge_sort(a, mid+1, high);
    count += merge(a, low, mid, high);
    

    return count;
}
int main(){
    vector<int> a{1 ,20 ,6 ,4 ,5};
    // vector<pair <int, int>> ans;
    int low = 0;
    int high = a.size()-1;

    cout<<"Number of inversion : "<<merge_sort(a, low, high)<<endl;

    // for(auto n: a)
    //     cout<<n<<" ";
    // cout<<endl;

    // int n = ans.size();
    // for(int i = 0; i<n; i++)
    //     cout<<"("<<ans[i].first<<" ,"<<ans[i].second<<"), ";

    // cout<<endl;


    return 0;
}
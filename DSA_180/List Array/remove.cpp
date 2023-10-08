#include<bits/stdc++.h>
using namespace std;


int removeDupli(vector<int> &a, int n){
    int i = 0;
    for(int j = 1; j<n; j++){
        if(a[i] != a[j]){
            i++;
            a[i] = a[j];
        }
    }

    a.erase(a.begin()+i+1, a.end());

    return i+1;
}



int main(){
    vector<int> v;
    int arr[] = {1, 1, 2, 2, 2, 2, 3, 3, 3 ,3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n; i++)
        v.push_back(arr[i]);

    int len = removeDupli(v, v.size());
    cout<<len<<endl;

    for(auto it: v)
        cout<<it<<" ";

    cout<<endl;

    

    return 0;
}
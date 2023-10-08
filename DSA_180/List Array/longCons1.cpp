#include<bits/stdc++.h>
using namespace std;


int removeDupli(vector<int> &a, int n){
    int i = 0, ans = 0;

    for(int j = 0; j<n; j++){
        int prevans = 0, i = j;
        if(a[j] == 1){
            while(a[j] == 1 && j<n)
                j++;
            
            prevans = j-i;
            if(prevans > ans)
                ans = prevans;
        }
    }

    return ans;
}



int main(){
    vector<int> v;
    int arr[] = {1, 1, 0, 1};
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
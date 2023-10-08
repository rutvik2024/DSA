#include<bits/stdc++.h>
using namespace std;

void show_1dvec(vector<int> &a){
    int n = a.size();

    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


vector<int> duplicates(vector<int> &arr, int n) {
    vector<int> temp(n,0);
    // show_1dvec(temp);
    
    for(int i = 0; i<n; i++){
        temp[arr[i]]++;
    }
    vector<int> ans;
    bool flag = true;
    for(int i = 0; i<n; i++){
        if(temp[i]>1){
            ans.push_back(i);
            flag = false;
        }
    }
    
    if(flag)
        ans.push_back(-1);
    return ans;
}

int main(){
    vector<int> a{3,1,3,4,2};
    vector<int> ans;
    
    ans = duplicates(a, a.size());
    show_1dvec(ans);


    return 0;
}
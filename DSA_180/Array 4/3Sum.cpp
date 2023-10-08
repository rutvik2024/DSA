#include<bits/stdc++.h>
using namespace std;

void show_vec(vector<vector<int>> &arr){
    int row = arr.size();
    int col = arr[0].size();

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ,";
        }cout<<endl;
    }
}


vector<vector<int>> sum3(vector<int> &a){
    int n = a.size();
    vector<vector<int>> ans;
    sort(a.begin(), a.end());

    for(int i = 0; i<n-2; i++){
        int left = i+1, right = n-1;
        int sum = 0 - a[i];

        if(i == 0 || (i > 0 && a[i] != a[i-1]) ){
            while(left < right){
                if(a[left] + a[right] == sum){
                    vector<int> temp;
                    temp.push_back(a[i]);
                    temp.push_back(a[left]);
                    temp.push_back(a[right]);

                    ans.push_back(temp);
                    while(left < right && a[left] == a[left + 1]){
                            left++;
                    }

                    while(left < right && a[right] == a[right-1]){
                            right--;
                    }

                    left++;
                    right--;
                }

                else if(a[left] + a[right] > sum){
                    right--;
                }

                else 
                    left++;
            }
        }

    }


    return ans;
}


int main(){
    vector<int> arr{-1,0,1,2,-1,-4};
    vector < vector < int >> ans;
    ans = sum3(arr);
    show_vec(ans);
    return 0;
}
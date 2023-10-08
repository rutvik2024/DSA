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

// Approach 1: Naive Brute force 2 for loop
// Time complexity : O(N^4) and Space complexity : O(n)
vector<vector<int>> sum4_brute(vector<int> &a, int target){
    
    set<vector<int>> st;
    int n = a.size();

    for(int i = 0; i<n-3; i++){
        for(int j = i+1; j<n-2; j++){
            for(int k = j+1; k<n-1; k++){
                for(int l = k+1; l<n; l++){
                    long long sum = a[i] + a[j];
                    sum += a[k];
                    sum += a[l];
                    if(sum == target){
                        vector<int> temp = {a[i], a[j], a[k],a[l]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// Approach 2: Using Hash Map 
// Time complexity : O(N^3 * log(N)) and Space complexity : O(N)
vector<vector<int>> sum4_better(vector<int> &a, int target){
    int n = a.size();
    set<vector<int>> st;

    for(int i = 0; i<n-2; i++){
        for(int j = i+1; j<n-1; j++){
            set <long long> hashset;
            for(int k = j+1; k<n; k++){
                long long four = target - a[i] - a[j];
                four -= a[k];

                if(hashset.find(four) != hashset.end()){
                    vector<int> temp = {a[i], a[j], a[k], (int)four};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(a[k]);
            }
        }
    }


    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Approach 3: Optimal Solution 
// Time complexity : O(N^3) and Space complexity : O(1)

vector<vector<int>> sum4_optim(vector<int> &a, int target){
    int n = a.size();
    sort(a.begin(), a.end());
    // set<vector<int>> st; 
    vector<vector<int>> ans;

    for(int i = 0; i<n-1; i++){
        if(i != 0 && a[i] == a[i-1]) continue;

        for(int j = i+1; j<n; j++){
            if(j != i+1 && a[j] == a[j-1]) continue;
            
            int left = j+1;
            int right = n-1;

            while(left < right){
                long long sum = a[i];
                sum += a[j];
                sum += a[left];
                sum += a[right];

                if(sum == target){
                    vector<int> temp = {a[i], a[j], a[left], a[right]};
                    ans.push_back(temp);
                    // st.insert(temp);

                    left++;
                    right--;

                    if(left < right && a[left] == a[left-1]) left++;

                    if(left < right && a[right] == a[right+1]) right--;
                }

                else if(sum > target)
                    right--;

                else
                    left++;
            }

        }
    }


    // vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



int main(){

    vector<int> arr{4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5};
    int target;

    cin>>target;

    vector<vector<int>> ans = sum4_better(arr, target);
    show_vec(ans);

    return 0;
}
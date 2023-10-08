#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using two for loop check one by one each element
// Time Complexity : O(n^2) space Complexity : O(1)

vector<int> majorityElementII_brute(vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();

	for(int i = 0; i<n; i++){

        if(ans.size() == 0 || ans[0] != arr[i]){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(arr[i] == arr[j])
                    count++;
            }

            if(count > n/3){
                ans.push_back(arr[i]);
            }
        }

        if(ans.size() == 2)
            break;
    }

    return ans;
}

// Approach 2: Store each element occurence and then check whatever element occurence is more than n/2 will be our ans
// Time Complexity : O(nlogn + n) space Complexity : O(n)
// Here we are using ordered map that's why time comlexity is O(nlogn + n) but if we use unordered map then it will be o(n + n)
vector<int> majorityElementII_better(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;
    // unordered_map<int, int> m;
    map<int, int> m;
    for(int i = 0; i<n; i++)
        m[arr[i]]++;

	for(auto it: m){
        if(it.second > (n/3))
            ans.push_back(it.first);
    }

    return ans;
}

// Approach 3: Using Extended Moore's Voting method
// Time Complexity : O(n) space Complexity : O(1)
vector<int> majorityElementII_optimal(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;
    int cn1 = 0, cn2 = 0;
    int elem1, elem2;

    for(int i = 0; i<n; i++){
        
        if(cn1 == 0 && elem2 != arr[i]){
            elem1 = arr[i];
            cn1 = 1;
        }

        else if(cn2 == 0 && elem1 != arr[i]){
            elem2 = arr[i];
            cn2 = 1;
        }

        else if(elem1 == arr[i])
            cn1++;

        else if(elem2 == arr[i])
            cn2++;

        else {
            cn1--;
            cn2--;
        }
    }

    int count1 = 0, count2 = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == elem1)
            count1++;

        if(arr[i] == elem2)
            count2++;
    }

    if(count1 > n/3)
        ans.push_back(elem1);

    if(count2 > n/3)
        ans.push_back(elem2);

    return ans;
}

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElementII_optimal(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";


    return 0;
}
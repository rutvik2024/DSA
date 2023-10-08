#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> mp;
        
        
        // Store frequency of each element in hash map
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        
        unordered_map<int, int> mp1;
        
        for(auto it: mp){
            if(mp1.find(it.second) != mp1.end())
                return false;
                
            mp1.insert({it.second, it.first});
        }
        
        return true;
    }
};


int main(){

    int arr[] = {2, 2, 5, 10, 1, 2, 10, 5, 10, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution obj = Solution();

    cout<<obj.isFrequencyUnique(size, arr)<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Approach 1: Bit manipulation technique
// This approach by me takes : time O(2n) and space O(1)
// This approach can identify only those element which appear for exactly 2 times.
int dupli_bit(vector<int> &a){
    int ans;
    int sum = 0;
    int suma = 0;
    int n = a.size();

    for(int i = 1; i<n ; i++){
        suma ^= i;
    }

    for(int i = 0; i<n ;i++){
        sum ^= a[i];
    }
    // cout<<"\nsum : "<<sum<<" suma: "<<suma<<endl;
    ans = suma^sum;
    // cout<<"Ans: "<<ans<<endl;

    return ans;
}

// Approach 2: Sorting technique
// This approach by me takes : time O(nlogn + n) and space O(1)
// This helpful for those element who appears for more than 2 times.
int dupli_sr(vector<int> &a){
    int n = a.size();
    
    // Sort array 
    sort(a.begin(), a.end());
    int i;
    for(i = 0; i<n-1; i++){
        if(a[i] == a[i+1]){
            break;
        }
    }

    return a[i];
}

// Approach 3: Extra space technique
// This approach by me takes : time O(2n) and space O(n)
// This helpful for those element who appears for more than 2 times.
int dupli_es(vector<int> &a){
    int n = a.size();
    vector<int> temp(n,0);
    for(int i = 0; i<n; i++){
        temp[a[i]-1]++;
    }

    int i;
    for(i = 0; i<n; i++){
        if(temp[i] > 1){
            break;
        }
    }

    return i+1;
}


// Approach 4: Same as above but using Map
// This approach by me takes : time O(2n) and space O(n)
// This helpful for those element who appears for more than 2 times.
int dupli_map(vector<int> &a){
    map<int, int> fre;
    int dupl;

    for(auto i = 0; i<a.size(); i++){
        ++fre[a[i]];
    }

    for(auto i:fre){
        if(i.second > 1){
            dupl = i.first;
            break;
        }
    }

    return dupl;
}


// Approach 5: binary search technique
// This approach by me takes : time O(nlogn) and space O(1)
// This helpful for those element who appears for more than 2 times.

int dupli_binary(vector<int> &a){
    int l = 0, h = a.size()-1, count;

    while(l <= h){
        int mid = l + (h-l)/2;
        count = 0;

        for(int n : a){
            if(n <= mid)
                count++;
        }

        if(count<=mid)
            l = mid+1;

        else
            h = mid-1;
    }

    return l;
}

// Approach 6: Linked List Cylce technique (Most Optimal Solution)
// This approach by me takes : time O(2n) and space O(1)
// This helpful for those element who appears for more than 2 times.
int dupli_cycle(vector<int> &a){
    int slow = a[0];
    int fast = a[0];

    // For finding first collide point
    do{
        slow = a[slow]; // Move by 1 step
        fast = a[a[fast]]; // Move by 2 step
    }while(slow != fast);

    fast = a[0]; // Update fast by a[0];

    // Now move both pointer by 1 step
    while(slow != fast){
        slow = a[slow];
        fast = a[fast];
    }

    return slow;
}



int main(){
    vector<int> a{2,5,9,6,9,3,8,9,7,1};
    int ans = dupli_binary(a);
    cout<<"Duplicate by Binary is: "<<ans<<endl;

    ans = dupli_bit(a);
    cout<<"Duplicate  by Bit is: "<<ans<<endl;

    ans = dupli_cycle(a);
    cout<<"Duplicate by Cycle is: "<<ans<<endl;

    ans = dupli_es(a);
    cout<<"Duplicate by Extra space is: "<<ans<<endl;

    ans = dupli_map(a);
    cout<<"Duplicate by Map is: "<<ans<<endl;

    ans = dupli_sr(a);
    cout<<"Duplicate by Sort is: "<<ans<<endl;


    return 0;
}
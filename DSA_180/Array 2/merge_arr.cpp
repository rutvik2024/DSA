#include<bits/stdc++.h>
using namespace std;
void show_1dvec(vector<long long> &a){
    int n = a.size();

    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// Brute force approach using extra space
void merge_brut(vector<long long> &a, vector<long long> &b){
    int sa= a.size(), sb = b.size(); 
    int i = 0, j = 0;
    vector<long long> temp;

    while(i < sa && j < sb){
        if(a[i] <= b[j]){
            temp.push_back(a[i]);
            i++;
        }

        else{
            temp.push_back(b[j]);
            j++;
        }


        // i++; j++;
    }

    // If there is element in vector a
    while(i < sa){
        temp.push_back(a[i]);
        i++;
    }

    // If there is element in vector b
    while(j < sb){
        temp.push_back(b[j]);
        j++;
    }

    int st = temp.size();

    for(int k = 0; k<st; k++){
        if(k < sa){
            a[k] = temp[k];
        }

        else{
            b[k-sa] = temp[k];
        }
    }

    show_1dvec(temp);
}

// Optimal Approach 2: using two pointer.
void merge_arr_2(vector<long long> &a, vector<long long> &b){
    int i= a.size()-1, j = 0, sb = b.size();
    bool flag = true;

    while(flag && i>=0){
        if(a[i] > b[j]){
            swap(a[i], b[j]);
            i--; j++;
        }

        else{
            flag = false;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// Approach 3: Gap Method:
void swapElem(vector<long long> &a, vector<long long> &b, int idx1, int idx2){
    if(a[idx1] > b[idx2])
        swap(a[idx1], b[idx2]);
}

void merge_gap(vector<long long> &a, vector<long long> &b, int n, int m){
    int len = n + m;

    int gap = len/2 + len%2;
    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            if(left < n && right >= n){
                swapElem(a, b, left, right-n);
            }

            // Both are in a    
            else if(right < n){
                swapElem(a, a, left, right);
            }

            // Both are in b
            else {
                swapElem(b, b, left-n, right-n);
            }

            right++;
            left++;
        }

        if(gap == 1){
            break;
        }

        gap = gap/2 + gap%2;
    }
}


// Approach by me : This passes 10 testcases out of 11
void merge_arr(vector<long long> &a, vector<long long> &b){
    int sa= a.size(), sb = b.size();
    int n = sa;
    
    for(int i = 0; i<n; i++){
        if(a[i] <= b[0])
            continue;

        else{
            swap(a[i], b[0]);
            sort(b.begin(), b.end());
        }
    }

}


int main(){

    vector<long long> a{1 ,1, 1, 1}, b{5, 5, 6, 6, 8};

    cout<<"Before merge: "<<endl;
    show_1dvec(a);
    show_1dvec(b);


    cout<<"After merge: "<<endl;
    // merge_arr(a,b);
    // merge_brut(a,b);
    merge_gap(a,b, a.size(), b.size());
    show_1dvec(a);
    show_1dvec(b);
    return 0;
}
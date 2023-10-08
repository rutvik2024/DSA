#include<bits/stdc++.h>
using namespace std;


pair<int, int> by_es(vector<int> &arr, int n){
    pair<int, int> ans;
	vector<int> frq(n,0);

	for(auto n: arr)
		frq[n-1]++;
	
	int i;

	for(i = 0; i<n; i++){
		if(frq[i] == 0)
			ans.first = i+1;

		if(frq[i] == 2)
			ans.second = i+1;	

	}

	return ans;
}

// Approach 2: Using Maths
// This takes O(n) time complexity and O(1) space complexity
pair<int, int> by_maths(vector<int> &arr, int n){

    pair<int, int> ans;
    // Find Sn and S2n:
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;

    for(auto n: arr){
        s+= (long long)n;
        s2 += (long long)n* (long long)n;
    }

    
    // s-sn = r-m;
    long long val1 = s-sn; 

    // s2-s2n = r2 - m2;
    long long val2 = s2-s2n;

    // r+m = (r2-m2)/(r-m)
    val2 = val2/val1;

    long long r = (long long)(val1+val2)/2;
    long long m = (long long)(r - val1);

    ans.first = (int)m;
    ans.second = (int)r;
    
    return ans;
}


// Approach 2: using Bit manipulation technique
// Utility function which help to find repeating number

int dupli_bit(vector<int> &a){
    int ans;
    int sum = 0;
    int suma = 0;
    int n = a.size();

    for(int i = 1; i<=n ; i++){
        suma ^= i;
    }

    for(int i = 0; i<n ;i++){
        sum ^= a[i];
    }
    cout<<"\nsum : "<<sum<<" suma: "<<suma<<endl;
    ans = suma^sum;
    cout<<"Ans: "<<ans<<endl;

    return ans;
}


pair<int, int> by_bit(vector<int> &arr, int n){
    pair<int, int> ans;
    ans.second = dupli_bit(arr); // give number which is repeating

    int s = 0, sn;

    for(auto n : arr)
        s += n;


    cout<<"S: "<<s<<endl;

    sn = n*(n+1)/2;
    cout<<"Sn: "<<sn<<endl;
    
    ans.first = ans.second - s + sn;


    return ans;
}



int main(){

    vector<int> a{3, 1, 2, 5, 4, 6, 7, 5};
    pair<int, int> ans;

    ans = by_maths(a, a.size());
    cout<<"Missing Number is : "<<ans.first<<" Repeating number is : "<<ans.second<<endl;

    return 0;
}
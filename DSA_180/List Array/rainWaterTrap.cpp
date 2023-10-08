#include<bits/stdc++.h>
using namespace std;

class Utils{
    public: 
        void printVec(vector<int> &a){
            for(auto it:a)
                cout<<it<<" ";

            cout<<endl;
        }

        vector<int> prefeMax(vector<int> &a){
            vector<int> ans;

            // cout<<"Preffix Sum is : "<<endl;
            int preans = INT_MIN;

            for(auto it:a){

                preans = max(it, preans);
                ans.push_back(preans);
            }
            return ans;
        }

        vector<int> SuffixMax(vector<int> &a){
            vector<int> ans(a.size(), 0);
            int preans = INT_MIN;
            // cout<<"Suffix Sum is : "<<endl;

            for(int i = a.size()-1; i>=0; i--){
                preans = max(a[i], preans);
                ans[i] = preans;
            }

            return ans;
        }
};

class Solution{
    public:

        // Brute Force Approach
        // Time Complexity : O(N^2)
        // Space Complexity : O(1)
        int rainTrap_brute(vector<int> &a){
            
            int n = a.size();
            int ans = 0;

            for(int i = 0; i < n; i++){
                int leftMax = INT_MIN;
                int rightMax = INT_MIN;
                int j = i;
                
                while(j >= 0){
                    leftMax = (leftMax, a[j]);
                    j--;
                }
                j = i;

                while(j < n){
                    rightMax = (rightMax, a[j]);
                    j++;
                }
                ans += (min(leftMax, rightMax) - a[i]);
            }

            return ans;
        }

        // Better Approach 
        // Time Complexity : O(3N)
        // Space Complexity : O(2N)
        int rainTrap_better(vector<int> &a){
            Utils ut = Utils();
            int n = a.size();
            vector<int> prefArr = ut.prefeMax(a);
            vector<int> suffArr = ut.SuffixMax(a);

            int ans = 0;
            for(int i = 0; i<n; i++){
                ans += (min(prefArr[i], suffArr[i]) - a[i]);
            }

            return ans;
        }

        // Optimal Approach 
        // Time Complexity : O(N)
        // Space Complexity : O(1)
        int rainTrap_optim(vector<int> &a){
            int ans = 0;
            int left = 0, right = a.size()-1;
            int leftMax = 0, rightMax = 0;


            while(left < right){
                if(a[left] <= a[right]){
                    if(a[left] >= leftMax)
                        leftMax = a[left];

                    else    
                        ans += (leftMax-a[left]);
                    
                    left++;
                }

                else{
                    if(a[right] >= rightMax)
                        rightMax = a[right];

                    else
                        ans += (rightMax - a[right]);

                    right--;
                }
            }

            return ans;
        }
};




int main(){
    Solution sol = Solution();
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    cout<<"Ans : "<<sol.rainTrap_optim(a)<<endl;


    return 0;
}
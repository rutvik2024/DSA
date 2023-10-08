#include<bits/stdc++.h>
using namespace std;


double pow(double x, int n){
    long long nn = n;
    if(nn < 0){
        nn = -1*nn;
    }
    if(nn == 0)
        return 1;

    double y = pow(x, nn/2);
    if(nn%2 == 0)
        return y*y;

    return x*y*y;
}

double myPow(double x, int n) {
    if(n < 0){
        return (double)1.0/ pow(x, n);
    }

    return pow(x,n);
    
}


// Another Approach 

double pow_app(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}


int main(){
    double x;
    int p;

    cin>>x>>p;
    cout<<x<<" to the power of "<<p<<" is :"<<myPow(x,p)<<endl;

    return 0;
}
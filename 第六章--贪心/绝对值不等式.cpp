#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
  int n;cin >> n;
  int a[n+1];
  for(int i = 1;i <= n;i ++) cin >> a[i];
  sort(a+1,a+n+1);
  int midd = a[n/2+1];
  int summ = 0;
  for(int i = 1;i <= n;i ++) summ += abs(midd-a[i]);
  cout << summ << endl;
  return 0;
}
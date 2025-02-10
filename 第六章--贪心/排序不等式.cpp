#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
  int n;cin >> n;
  int a[n];
  for(int i = 0;i < n;i ++) cin >> a[i];
  sort(a,a+n);
  int ans = 0;
  for(int i = 0;i < n;i ++) ans += (a[i] * (n - i - 1));
  cout << ans << endl;
  return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 10010;
bool stdd[N];
int phi[N];
int prime[N],cnt;
void get_add(int n){
  for(int i = 2;i <= n;i ++){
    if(!stdd[i]){
      prime[cnt++] = i;
      phi[i] = i - 1;
    }
    for(int j = 0;prime[j] <= n / i;j ++){
      int x = prime[j] * i;
      stdd[x] = true;
      if(i % prime[j] == 0){
        phi[x] = prime[j] * phi[i];
        break;
      }
      else phi[x] = (prime[j] - 1) * phi[i];
    }
  }
}
int main(){
  int n;cin >> n;
  get_add(n);
  phi[1] = 1;
  LL sum = 0;
  for(int i = 1;i <= n;i ++){
     sum += phi[i];
  }
  cout << sum << endl;
  return 0;
}

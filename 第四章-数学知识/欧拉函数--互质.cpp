/*1∼N中与 N 互质的数的个数被称为欧拉函数，记为 ϕ(N)。
若在算数基本定理中，N=pa11pa22…pamm
，则：ϕ(N) = N×p1−1p1×p2−1p2×…×pm−1pm
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;cin >> n;
  while(n--){
    int a;cin >> a;
    int res = a;
    for(int i = 2;i <= a / i;i ++){
      if(a % i == 0){
        res = res / i * (i - 1);
        while(a % i == 0) a /= i;
      }
    }
    if(a > 1) res = res / a * (a - 1);
    cout << res << endl;
  }
  return 0;
}
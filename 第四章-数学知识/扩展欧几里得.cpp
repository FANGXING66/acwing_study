#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
int exgcdd(int a,int b,int &x,int &y){
  if(!b){
    x = 1,y = 0;
    return a;
  }
  int x1,y1;
  int d = exgcdd(b,a%b,x1,y1);
  x = y1,y = x1 - a/b*y1;
  return d;
}
int main(){
  int n;cin >> n;
  while(n --){
    int a,b,m,x,y;cin >> a >> b >> m;
    int d = exgcdd(a,m,x,y);
    if(b % d) cout << "impossible" << endl;
    else cout << (LL) b/d*x % m<< endl;
  }
}
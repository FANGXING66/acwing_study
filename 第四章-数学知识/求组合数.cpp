#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2010;
const int modd = 1e9 + 7;
long long f[N][N];
int main(){
  for(int i = 0;i <= 2000;i ++){
    for(int j = 0;j <= i;j ++){
      if(!j){
        f[i][j] = 1;
      }
      else{
        f[i][j] = (f[i-1][j-1] + f[i-1][j]) % modd;
      }
    }
  }

  int n;cin >> n;
  while(n --){
    int a,b;cin >> a >> b;
    cout << f[a][b] << endl;
  }
}
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 110;
const double eps = 1e-8;
int n;
double a[N][N];

int gaosi(){
  int c,r;
  for(r = 0,c = 0;c < n;c ++){
    //找最大起始位置不为0
    int t = r;
    for(int i = r;i < n;i++){
      if(fabs(a[i][c]) > fabs(a[t][c])){
        t = i;
      }
    }
    //异常判断
    if(fabs(a[t][c]) < eps) continue;
    //交换行列，主要交换列数字,r此时代表start行
    for(int i = c;i <= n;i ++) swap(a[t][i],a[r][i]);
    //变为1,对‘首行’改变
    for(int i = n;i >= c;i --) a[r][i] /= a[r][c];
    //剩下首个为0,这里因为啊a[r][c]为1
    for(int i = r + 1;i < n;i ++){
      if(fabs(a[i][c]) > eps){
        for(int j = n;j >= c;j --){
          a[i][j] -= a[r][j] * a[i][c];
        }
      }
    }
     r++;
  }
  if(r < n){
    for(int i = r;i < n;i ++){
      if(fabs(a[i][n]) > eps){
        return 2;
      }
    }
    return 1;
  }
  for(int i = n-1;i >= 0;i --){
    for(int j = i+1;j < n;j ++){
      a[i][n] -= a[i][j] * a[j][n];
    }
  }
  return 0;
}
int main(){
  cin >> n;
  for(int i = 0;i < n;i ++){
    for(int j = 0;j <= n;j ++){
      cin >> a[i][j];
    }
  }

  int t = gaosi();
  if(t == 2) cout << "No solution" << endl;
  else if(t == 1) cout << "Infinite group solutions" << endl;
  else{
    for(int i = 0;i < n;i ++){
      printf("%.2lf\n",a[i][n]);
    }
  }
}
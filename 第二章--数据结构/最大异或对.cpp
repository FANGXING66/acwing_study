#include<bits/stdc++.h>
using namespace std;
int const N=100010,M=31*N;
int a[N];
int son[M][2],idx;
void insert(int x){
  int p = 0;
  for(int i = 30;i >= 0;i --){
    int u = x >> i & 1;
    if(!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
}
int search(int x){
  // 从根节点开始搜索
  int p = 0;
  // 初始化结果为0
  int res = 0;
  // 从高位到低位遍历整数x的每一位
  for(int i = 30;i >= 0;i --){
    // 获取x的第i位
    int u = x>>i&1;
    // 如果存在与x的第i位相反的子节点，则选择该子节点
    if(son[p][!u]){
      p = son[p][!u];
      // 更新结果，将结果左移一位并加上1
      res = res*2+1;
    }
    // 否则选择与x的第i位相同的子节点
    else{
      p = son[p][u];
      // 更新结果，将结果左移一位并加上0
      res=res*2+0;
    }
  }
  // 返回与x异或结果最大的整数
  return res;
}
int main(){
  int n;cin >> n;
  idx=0;
  for(int i = 0;i < n;i ++ ) cin >> a[i],insert(a[i]);

  int res=0;

  for(int i = 0;i < n;i ++){
    res = max(res,search(a[i]));
  }
   cout << res << endl;
}
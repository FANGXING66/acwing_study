//求最大值,一种排序求最小与最大
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int num[N],len;
int down(int u){
  int t = u;
  if(u * 2 <= len && num[u*2] < num[t]) t = u*2;
  if(u * 2 + 1 <= len && num[u*2+1] < num[t]) t = u*2 + 1;
  if(u != t){
    swap(num[u],num[t]);
    down(t);
  }
}
int main(){
  int n,m; scanf("%d%d", &n, &m);
  for(int i = 1;i <= n;i ++) cin >> num[i];
  len = n;

  for(int i = n/2;i;i--) down(i); //代表下标

  while(m--){
    printf("%d ",num[1]);
    num[1] = num[len];len--;
    down(1);
  }
  return 0;
}
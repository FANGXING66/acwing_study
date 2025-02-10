#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], idx;
bool st[N];
int match[N];
int n1, n2, m;
void add(int a,int b){
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++;
}
// 定义函数 find，用于寻找增广路径
int find(int x){
  // 遍历 x 的所有邻接节点
  for(int i = h[x];i != -1;i = ne[i]){
    // 获取邻接节点的编号
    int j = e[i];
    // 如果邻接节点未被访问
    if(!st[j]){
      // 标记邻接节点为已访问
      st[j] = true;
      // 如果邻接节点未匹配，或者邻接节点的匹配节点可以找到增广路径
      if(!match[j] || find(match[j])){
        // 更新邻接节点的匹配节点为 x
        match[j] = x;
        // 返回匹配成功
        return true;
      }
    }
  }
  // 返回匹配失败
  return false;
}
int main(){
  cin >> n1 >> n2 >> m;
  memset(h, -1, sizeof h);
  while(m --){
    int a,b;cin >> a >> b;
    add(a,b);
  }
  int res = 0;
  for(int i = 1;i <= n1;i ++){
    memset(st, 0, sizeof st);
    if(find(i)) res ++;
  }
  cout << res;
  return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 10; //数据范围是10的5次方
const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
int e[M]; //存储元素
int ne[M]; //存储列表的next值
int idx; //单链表指针
int n; //题目所给的输入，n个节点
int ans = N; //表示重心的所有的子树中，最大的子树的结点数目

bool st[N]; //记录节点是否被访问过，访问过则标记为true
void add(int x,int y){
  e[idx] = y;
  ne[idx] = h[x];
  h[x] = idx ++;
}
// 定义深度优先搜索函数，u 表示当前节点
int dfs(int u){
  // 标记当前节点已访问
  st[u] = true;
  // 初始化结果和子树节点数
  int res = 0;
  int sum = 1;
  // 遍历当前节点的所有邻居
  for(int i = h[u];i != -1;i = ne[i]){
    int j = e[i];
    // 如果邻居节点未访问
    if(!st[j]){
      // 递归计算邻居节点的子树节点数
      int s = dfs(j);
      // 更新结果为最大子树节点数
      res = max(res,s);
      // 更新子树节点数
      sum += s;
    }
  }
  // 更新结果为最大子树节点数和剩余节点数的最大值
  res = max(res,n-sum);
  // 更新答案为最小的最大子树节点数
  ans = min(ans,res);
  // 返回以当前节点为根的子树的节点数
  return sum;
}
int main(){
  cin >> n;
  memset(h,-1,sizeof h);
  for(int i = 0;i < n-1;i ++){
    int a,b;cin >> a >> b;
    add(a,b);
    add(b,a);
  }
  dfs(1);
  cout << ans;
  return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];// 保存1号点到各个点的距离int idx; //单链表指针
void add(int a,int b){
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++;
}
int bfs(){
  memset(d,-1,sizeof d);
  queue<int> q;
  d[1] = 0;
  q.push(1);
  while(q.size()){
    int t = q.front();
    q.pop();
    for(int i = h[t];i != -1;i = ne[i]){
      int j = e[i];
      if(d[j] == -1){
        d[j] = d[t] + 1;
        q.push(j);
      }
    }
  }
  return d[n];
}
int main(){
    // 初始化邻接表，将所有节点的头指针初始化为-1，表示没有邻接节点
    memset(h,-1,sizeof h);
    // 读取节点数n和边数m
    cin >> n >> m;
    // 循环读取m条边，将每条边的两个端点添加到邻接表中
    for(int i = 0;i < m;i ++){
        int a,b;cin >> a >> b;
        add(a,b);
    }
    // 调用bfs函数，从节点1开始进行广度优先搜索，并输出节点1到节点n的最短距离
    cout << bfs();
    return 0;
}
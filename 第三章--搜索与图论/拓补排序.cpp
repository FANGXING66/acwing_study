#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N], ne[N], idx;//邻接表存储图
int h[N];
int p[N], hh = 0, tt = -1;//队列保存入度为0的点，也就是能够输出的点，
int n, m;//保存图的点数和边数
int d[N];////保存各个点的入度
void add(int x,int y){
  // 将边的终点存储在邻接表中
  e[idx] = y;
  // 将当前边的下一条边指向起点的第一条边
  ne[idx] = h[x];
  // 更新起点的第一条边为当前边
  h[x] = idx ++;
}
void tosort(){
  for(int i = 1;i <= n;i ++){
    if(d[i] == 0){
      p[++ tt] = i;
    }
  }
    // 当队列不为空时，进行拓扑排序
    while(hh <= tt) {
        // 取出队头节点
        int t = p[hh++];
        // 遍历队头节点的所有出边
        for(int i = h[t]; i != -1; i = ne[i]) {
            // 获取出边指向的节点
            int j = e[i];
            // 减少出边指向节点的入度
            d[j]--;
            // 如果出边指向节点的入度为0，则将其入队
            if(d[j] == 0) {
                p[++tt] = j;
            }
        }
    }
    // 如果所有节点都被访问过，则输出拓扑排序结果
    if(tt == n - 1) {
        for(int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
    // 如果存在环，则输出-1
    } 
    else {
        cout << "-1";
    }
}

int main(){
  cin >> n >> m;
  memset(h,-1,sizeof h);
  while(m--){
    int a,b;cin >> a >> b;
    add(a,b);
    d[b]++;
  }
  tosort();
  return 0;
}
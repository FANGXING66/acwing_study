#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1010;
int d[N];
int g[N][N];
bool st[N];
int pre[N];
int n,m;
/**
 * @brief Prim算法实现
 * 
 * 该函数实现了Prim算法，用于计算无向图的最小生成树。
 * 
 * @param n 图中顶点的数量
 * @param m 图中边的数量
 * @param g 二维数组，表示图的邻接矩阵，g[i][j]表示顶点i到顶点j的边的权值
 * @param d 一维数组，表示顶点到最小生成树的最小距离
 * @param st 一维数组，表示顶点是否已经被加入最小生成树
 * @param pre 一维数组，表示顶点在最小生成树中的前驱顶点
 */
void prim() {
    // 初始化d数组为无穷大
    memset(d, 0x3f, sizeof d);
    // 初始化结果变量为0
    int res = 0;
    // 将顶点1到最小生成树的距离初始化为0
    d[1] = 0;

    // 循环n次，每次选择一个顶点加入最小生成树
    for (int i = 0; i < n; i++) {
        // 初始化t为-1，表示未找到距离最小生成树最近的顶点
        int t = -1;
        // 遍历所有顶点，找到距离最小生成树最近的顶点t
        for (int j = 1; j <= n; j++) {
            // 如果t未被选中或者顶点j到最小生成树的距离比t更小，并且顶点j尚未被选中，则更新t为顶点j
            if ((t == -1 || d[t] > d[j]) && (!st[j])) t = j;
        }

        // 如果找到的顶点t到最小生成树的距离仍然是无穷大，说明图不连通，无法构建最小生成树，输出"impossible"并结束程序
        if(d[t] == 0x3f3f3f3f) {cout << "impossible" << endl;return;}

        // 将顶点t标记为已选中
        st[t] = true;
        // 累加顶点t到最小生成树的距离到结果变量res中
        res += d[t];

        // 遍历所有顶点，更新与顶点t相邻的顶点到最小生成树的距离
        for (int j = 1; j <= n; j++) {
            // 如果顶点j到最小生成树的距离大于顶点t到顶点j的距离，并且顶点j尚未被选中，则更新顶点j到最小生成树的距离为g[t][j]，并记录顶点j的前驱顶点为t
            if (d[j] > g[t][j] && !st[j]) {
                d[j] = g[t][j];
                pre[j] = t;
            }
        }
    }
    // 输出最小生成树的总权值
    cout << res << endl;
}
void get_path(){
  for(int i = 1;i <= n;i ++){
    cout << i << " " << pre[i] << endl;
  }
}

int main(){
  memset(g,0x3f,sizeof g);
  cin >> n >> m;
  while(m--){
    int a,b,c;cin >> a >> b >> c;
    g[a][b] = g[b][a] = min(g[a][b],c);
  }

  prim();

  return 0;
}
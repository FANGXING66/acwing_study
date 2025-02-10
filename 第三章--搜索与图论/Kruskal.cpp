#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200010;
int p[N];
int n,m;
struct eage{
  int a,b,w;
  /**
   * @brief 重载小于运算符
   * 
   * 该函数重载了小于运算符，用于比较两个边的权重。
   * 
   * @param W 另一个边对象
   * @return bool 如果当前边的权重小于W的权重，返回true，否则返回false
   */
  bool operator<(const eage &W) const{
    // 返回当前边的权重是否小于W的权重
    return w < W.w;
  }
}eages[N];
int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}
/**
 * @brief Kruskal算法实现
 * 
 * 该函数实现了Kruskal算法，用于计算无向图的最小生成树。
 * 
 * @param eages 存储图中所有边的数组
 * @param n 图中顶点的数量
 * @param m 图中边的数量
 * @param p 并查集数组，用于判断两个顶点是否在同一个连通分量中
 * @param res 最小生成树的总权值
 * @param ans 最小生成树中的边数
 */
void kruskal() {
    // 初始化最小生成树的总权值为0
    int res = 0;
    // 初始化最小生成树中的边数为0
    int ans = 0;
    // 遍历所有边
    for (int i = 1; i <= m; i++) {
        // 获取当前边的两个端点和权值
        int a = eages[i].a;
        int b = eages[i].b;
        int w = eages[i].w;

        // 查找端点a和b所在的连通分量的根节点
        a = find(a);
        b = find(b);

        // 如果端点a和b不在同一个连通分量中
        if (a != b) {
            // 将端点a所在的连通分量合并到端点b所在的连通分量中
            p[a] = b;
            // 累加当前边的权值到最小生成树的总权值中
            res += w;
            // 最小生成树中的边数加1
            ans++;
        }
    }

    // 如果最小生成树中的边数小于顶点数减1，说明图不连通，无法构建最小生成树，输出"impossible"
    if (ans < n - 1) cout << "impossible" << endl;
    // 否则，输出最小生成树的总权值
    else cout << res << endl;
}
int main(){
  cin >> n >> m;
  for(int i = 1;i <= n;i ++) p[i] = i;
  for(int i = 1;i <= m;i ++){
    int a,b,w;cin >> a >> b >> w;
    eages[i] = {a,b,w};
  }
  sort(eages + 1,eages + 1 + m);
  kruskal();
  return 0;
}
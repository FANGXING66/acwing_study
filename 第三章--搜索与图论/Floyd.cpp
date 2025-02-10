//O(n^3)
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int d[N][N];
int n,m,k;
/**
 * @brief Floyd算法实现
 * 
 * 该函数实现了Floyd算法，用于计算图中所有顶点对之间的最短路径。
 * 
 * @param n 图中顶点的数量
 * @param d 二维数组，表示图的邻接矩阵，d[i][j]表示顶点i到顶点j的最短路径长度
 */
void floyd() {
    // 遍历所有顶点，作为中间顶点
    for (int i = 1; i <= n; i++) {
        // 遍历所有顶点，作为起始顶点
        for (int j = 1; j <= n; j++) {
            // 遍历所有顶点，作为结束顶点
            for (int z = 1; z <= n; z++) {
                // 更新d[j][z]为从j到z经过i的最短路径长度
                d[j][z] = min(d[j][z], d[j][i] + d[i][z]);
            }
        }
    }
}

/**
 * @brief 主函数
 * 
 * 主函数负责读取输入，初始化图的邻接矩阵，调用Floyd算法，并输出结果。
 * 
 * @return int 程序的返回值
 */
int main() {
  cin >> n >> m >> k;
  
  for(int i = 1;i <= n;i ++){
    for(int j = 1;j <= n;j ++){
      if(i == j) d[i][j] = 0;
      else d[i][j] = 0x3f3f3f3f;
    }
  }
  
  while(m--){
    int a,b,c;cin >> a >> b >> c;
    d[a][b]  = min(d[a][b],c);
  }

  floyd();

  while(k--){
    int a,b;cin >> a >> b;
    if(d[a][b] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << d[a][b] << endl;
  }
}
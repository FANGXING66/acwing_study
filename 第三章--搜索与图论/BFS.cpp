#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 100;
int g[N][N];
int f[N][N];
int n,m;
// 定义一个广度优先搜索函数，用于计算从起点 (x, y) 到终点的最短路径
int bfs(int x, int y) {
    // 创建一个队列用于存储待处理的节点
    queue<PII> q;
    // 初始化起点的步数为0
    f[x][y] = 0;
    // 将起点加入队列
    q.push({x, y});

    // 当队列不为空时，继续处理节点
    while (q.size()) {
        // 取出队列的头部节点
        auto t = q.front();
        q.pop();
        // 定义四个方向的偏移量：右、左、下、上
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            // 计算新的坐标
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            // 判断新坐标是否在地图范围内，并且是可通行的（值为0）且未被访问过（值为0）
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0 && f[a][b] == 0) {
                // 标记新坐标为已访问
                g[a][b] = 1;
                // 更新新坐标的步数，为当前节点步数加1
                f[a][b] = f[t.first][t.second] + 1;
                // 将新坐标加入队列
                q.push({a, b});
            }
        }
    }
    // 输出终点的步数
    cout << f[n - 1][m - 1];
}
int main() {
  cin >> n >> m;
  for(int i = 0;i < n;i ++){
    for(int j = 0;j < m;j ++){
      cin >> g[i][j];
    }
  }
  bfs(0,0);
  return 0;
}
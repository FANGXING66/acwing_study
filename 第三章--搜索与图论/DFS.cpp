#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100;
int path[N];
bool used[N];
int n;
// 定义深度优先搜索函数，u 表示当前搜索的层数
int dfs(int u){
  // 如果当前搜索的层数等于 n，表示找到了一个全排列
  if(u == n) {
    // 输出当前找到的全排列
    for(int i = 0;i < n;i ++) cout << path[i] << " ";
    cout << endl;
  }

  // 遍历从 1 到 n 的所有数字
  for(int i = 1;i <= n;i ++){
    // 如果数字 i 还没有被使用过
    if(!used[i]){
      // 将数字 i 放入当前位置
      path[u] = i;
      // 标记数字 i 为已使用
      used[i] = true;
      // 递归搜索下一层
      dfs(u + 1);
      // 回溯，将数字 i 标记为未使用
      used[i] = false;
    }
  }
}

// 主函数
int main(){
  cin >> n;
  dfs(0);
  return 0;
}
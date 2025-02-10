#include<iostream>
#include<algorithm>
using namespace std;
const int N = 21;
char s[N][N];
int n;
bool dg[N],udg[N],col[N];
// 深度优先搜索函数，用于放置皇后
void dfs(int r){
  // 如果已经放置了n个皇后，输出当前棋盘状态并换行
  if(r == n){
    for(int i = 0 ;i < n;i ++ ) puts(s[i]);
    cout << endl;
  }

  // 遍历当前行的每一列
  for(int i = 0;i < n;i ++){
    // 如果当前列、正对角线和反对角线都没有皇后
    if(!col[i] && !udg[i+r] && !dg[n-i+r]){
      // 在当前位置放置皇后
      s[r][i] = 'Q';
      // 标记当前列、正对角线和反对角线已有皇后
      col[i] = udg[r+i] = dg[n-i+r] = true;
      // 递归搜索下一行
      dfs(r+1);
      // 回溯，撤销当前位置的皇后
      col[i] = udg[r+i] = dg[n-i+r] = false;
      s[r][i] = '.';
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i ++){
    for(int j = 0;j < n;j ++){
      s[i][j] = '.';
    }
  }
  dfs(0);
}
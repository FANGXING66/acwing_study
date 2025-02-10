//集合中查询字符串
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int son[N][26],cnt[N],idx;
char str[N];
// 插入字符串到Trie树中
void insert(char str[]){
  // 初始化指针p指向根节点
  int p = 0;
  // 遍历字符串中的每个字符
  for(int i = 0;str[i];i ++){
    // 将字符转换为对应的索引值
    int u = str[i] - 'a';
    // 如果当前节点的子节点中不存在该字符对应的节点，则创建一个新的节点
    if(!son[p][u]) son[p][u] = ++idx; 
    // 将指针p指向新创建的节点
    p = son[p][u];
  }
  // 标记当前节点表示的字符串出现的次数加1
  cnt[p] ++;
}
/**
 * 查询字符串在Trie树中出现的次数
 * @param str 要查询的字符串
 * @return 字符串在Trie树中出现的次数
 */
int query(char str[]) {
  // 初始化指针p指向根节点
  int p = 0;
  // 遍历字符串中的每个字符
  for(int i = 0; str[i]; i++) {
    // 将字符转换为对应的索引值
    int u = str[i] - 'a';
    // 如果当前节点的子节点中不存在该字符对应的节点，则表示该字符串不存在，返回0
    if(!son[p][u]) return 0;
    // 将指针p指向新创建的节点
    p = son[p][u];
  }
  // 返回当前节点表示的字符串出现的次数
  return cnt[p];
}
int main(){
  int n;cin >> n;
  while(n--){
    char op[2];
    scanf("%s%s",op,str);
    if(*op == 'I'){
      insert(str);
    }else{
      cout << query(str) << endl;
    }
  }
}
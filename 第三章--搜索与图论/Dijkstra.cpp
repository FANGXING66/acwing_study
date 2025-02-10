#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
bool used[N];
int g[N][N];
int minn[N];
int n,m;
int dijikstra(){
  memset(minn,0x3f,sizeof minn);
  minn[1] = 0;
  for(int i = 0;i < n;i ++){

    int t  = -1;
    for(int j = 1;j <= n;j ++){
      if(used[j] == false && (t == -1 || minn[j] < minn[t])){
        t = j;
      }
    }
    
    used[t] = true;

    for(int j = 1;j <= n;j ++){
      minn[j] = min(minn[j],minn[t] + g[t][j]);
    }

  }
  if(minn[n] == 0x3f3f3f3f){
    return -1;
  }
  return minn[n];
}
int main(){
  cin >> n >> m;

  memset(g,0x3f,sizeof g);

  while(m--){
    int a,b,c;cin >> a >> b >>c;
    g[a][b] = min(g[a][b],c);
  }

  int t = dijikstra();
  cout << t;
  return 0;
}
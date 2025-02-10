#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;
const int N = 10010;
int ss[N],f[N];
int n,m;
int sg(int x){
  if(f[x] != -1) return f[x];

  unordered_set<int>s;
  for(int i = 0;i < m;i ++){
    if(x >= ss[i]) {
      s.insert(sg(x - ss[i]));
    }
  }
  for(int i = 0;;i++){
    if(!s.count(i)){
      return f[x] = i;
    }
  }
}
int main(){
  cin >> m;
  for(int i = 0;i < m;i ++) cin >> ss[i];
  memset(f,-1,sizeof f);
  cin >> n;
  int res = 0;
  while(n--){
    int x;cin >> x;
    res ^= sg(x);
  }
  if(res) cout << "Yes" <<endl;
  else cout << "No" << endl;
}
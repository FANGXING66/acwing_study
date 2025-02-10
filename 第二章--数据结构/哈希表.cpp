//看是否出现过
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100003;
int e[N],ne[N],h[N],idx;
void insert(int x){
  int k = (x % N + N) % N;
  e[idx] = x;
  ne[idx] = h[k];
  h[k] = idx ++;
}
bool find(int x){
  int k = (x % N + N) % N;
  for(int i = h[k];i != -1;i = ne[i]){
    if(e[i] == x) return true;
  }
  return false;
}
int main(){
  int n;cin >> n;
  memset(h, -1, sizeof h);
  while(n --){
    string s;cin >> s;
    int x;cin >> x;
    if(s == "I"){
      insert(x);
    }
    else{
      if(find(x)) puts("Yes");
      else puts("No");
    }
  }
}
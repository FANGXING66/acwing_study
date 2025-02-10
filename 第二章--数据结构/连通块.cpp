#include<iostream>
using namespace std;
const int N = 10010;
int p[N],siz[N];
int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}
int main(){
  int m,n;cin >> m >> n;
  for(int i = 1;i <= m;i ++) p[i] = i,siz[i] = 1;
  
  while(n--){
    string s;cin >> s;
    int a,b;
    if(s == "C"){
      cin >> a >> b;
      a = find(a), b = find(b);
      if (a != b)
      {
          p[a] = b;
          siz[b] += siz[a];
      }
    }
    else if(s == "Q1"){
       cin >> a >> b;
       if(find(a) == find(b)){
        cout << "Yes" << endl;
       }
       else{
        cout << "No" << endl;
       }
    }
    else{
       cin >> a;
       cout << siz[find(a)] << endl;
    }
  }
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void yueshu(int x){
  vector<int>a;
  for(int i = 1;i <= x/i;i ++){
    if(x % i == 0){
      a.push_back(i);
      if(i != x/i){
        a.push_back(x/i);
      }
    }
  }

  sort(a.begin(),a.end());

  for(auto item : a){
    cout << item << " ";
  }
  cout << endl;
}
int main(){
  int n;cin >> n;
  while(n --){
    int x;cin >> x;
    yueshu(x);
  }
  return 0;
}
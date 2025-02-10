#include<iostream>
#include<algorithm>
using namespace std;
void gcdd(int a,int b){
  while(a % b){
    int c = a % b;
    a = b;
    b = c;
  }
  cout << b << endl;
}
int main(){
  int n;cin >> n;
  while(n--){
    int a,b;cin >> a >> b;
    gcdd(a,b);
  }
}
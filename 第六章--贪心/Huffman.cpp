#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
  priority_queue<int,vector<int>,greater<int>> huffman;
  int n;cin >> n;
  while(n--){
    int x;cin >> x;
    huffman.push(x);
  }
  int res = 0;
  while(huffman.size() > 1){
      int a = huffman.top();
      huffman.pop();
      int b = huffman.top();
      huffman.pop();
      res += (a+b);
      huffman.push(a+b);
  }
  cout << res << endl;
  return 0;
}

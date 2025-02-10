/*H x����ʾ������ͷ����һ���� x
  D k����ʾɾ���� k�������������������� kΪ 0ʱ����ʾɾ��ͷ��㣩��
  I k x����ʾ�ڵ� k����������������һ���� x
*/
#include <iostream>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int e[N],ne[N];
int idx,head;
void init(){
    head = -1;
    idx = 0;
}
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
void add(int k,int x){
    ne[idx] = ne[k];
    ne[k] = idx;
    e[idx] = x;
    idx++;
}
void Delete(int k){
    ne[k] = ne[ne[k]];
}
signed main()
{
    int m;cin >> m;
    init();
    while(m--){
        char op;cin >> op;
        if(op == 'H'){
            int number;cin >> number;
            add_to_head(number);
        }
        else if(op == 'D'){
            int k;cin >> k;
            if(!k) head = ne[head];
            else Delete(k-1);
        }
        else{
            int k,x;cin >> k >> x;
            add(k-1,x);
        }
    }
    for(int i = head;i != -1;i = ne[i]) cout << e[i] << " ";
    return 0;
}
/*L x，表示在链表的最左端插入数 x
R x，表示在链表的最右端插入数 x
D k，表示将第 k个插入的数删除。
IL k x，表示在第 k个插入的数左侧插入一个数。
IR k x，表示在第 k个插入的数右侧插入一个数。
*/ 
#include <iostream>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int e[N],l[N],r[N],idx,head;
void init(){
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}
void add(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    l[idx] = k;
    idx++;
}
void Delete(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
signed main()
{
    int m;cin >> m;
    init();
    while(m--){
        string op;cin >> op;
        if(op == "L"){
            int number;cin >> number;
            add(0,number);
        }
        else if(op == "R"){
            int number;cin >> number;
            add(l[1],number);
        }
        else if(op == "D"){
            int k;cin >> k;
            Delete(k+1);
        }
        else if(op == "IL"){
            int k;cin >> k;
            int x;cin >> x;
            add(l[k+1],x);
        }
        else{
            int k,x;cin >> k >> x;
            add(k+1,x);
        }
    }

    for(int i = r[0];i != 1;i = r[i]) cout << e[i] << " ";
    return 0;
}
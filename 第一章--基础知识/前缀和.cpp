#include <iostream>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int a[N],p[N];
int n;
signed main()
{
    cin >> n;
    int m;cin >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= n;i ++) p[i] = p[i-1] + a[i];
    
    while(m--){
        int l,r;cin >> l >> r;
        cout << p[r] - p[l-1] << endl;
    }
    //for(int i = 1;i <= n;i ++) cout << p[i] << '\n';
    return 0;
}
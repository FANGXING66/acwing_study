#include <iostream>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int str[N];

signed main()
{
    int n;cin >> n;
    int tt = 0;
    while(n --){
        int x;cin >> x;
        while(tt && str[tt] >= x) tt--;
        if(tt <= 0) cout << "-1" << " ";
        else printf("%d ",str[tt]);
        tt++;
        str[tt] = x;
    }
    return 0;
}
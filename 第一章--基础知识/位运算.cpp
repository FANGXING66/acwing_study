#include <iostream>
using namespace std;
#define int long long
signed main()
{
    int n;cin >> n;
    while(n--){
        int m;cin >> m;
        int ans = 0;
        while(m){
            if(m & 1) ans ++;
            m >>= 1;
        }
        cout << ans << " ";
    }

    return 0;
}
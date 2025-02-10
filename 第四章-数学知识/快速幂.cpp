#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
void qmi(int a,int b,int p){
     LL res = 1;
     while(b){
        if(b&1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
     }
     cout << res << endl;
}
signed main()
{
    LL n;cin >> n;
    while(n--){
     LL a,b,p;
     cin >> a >> b >> p;
     qmi(a,b,p);
    }
    return 0;
}
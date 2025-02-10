#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N =100;
int p[N],n,m;
signed main(){
    cin >> n >> m;
    for(int i = 0;i < m;i ++) cin >> p[i];
    int res = 0;
    for(int i = 1;i < 1 << m;i ++){
        int t = 1;
        int s = 0;
        for(int j = 0;j < m;j ++){
            if(i >> j & 1){
                if(t * p[j] > n){
                    t = -1;
                    break;
                }

                s ++;
                t *= p[j];
            }
        }
        if(t == -1) continue;
        if(s % 2) res += n / t;
        else res -= n / t; 
    }
    cout << res << endl;
    return 0;
}
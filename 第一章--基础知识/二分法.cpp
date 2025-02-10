#include <iostream>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int q[N];
int n;
signed main()
{
    cin >> n;
    int m;cin >> m;
    for(int i = 0;i < n;i ++) cin >> q[i];
    while(m --){
        int number;cin >> number;
        int l = 0,r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= number) r = mid;
            else l = mid + 1;
        }
        if(q[l] != number){
           cout << -1 << " " << -1 << endl;
        }
        else{
            cout << l << " ";
            int l = 0,r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(q[mid] <= number) l = mid;
                else r = mid - 1;
        }
        cout << l << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
#define int long long
const int N = 1000010;
deque<int> q;
int a[N];

signed main() {
    int n; cin >> n;
    int k; cin >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 计算滑动窗口的最小值
    for (int i = 1; i <= n; i++) {
        // 移除大于当前元素的元素
        while (q.size() && q.back() > a[i]) q.pop_back();
        q.push_back(a[i]);
        // 输出当前窗口的最小值
        if (i >= k) {
            cout << q.front() << " ";
            // 如果窗口左边界的元素是最小值，则移除它
            if (a[i - k + 1] == q.front()) q.pop_front();
        }
    }
    cout << endl;

    q.clear();
    // 计算滑动窗口的最大值
    for (int i = 1; i <= n; i++) {
        // 移除小于当前元素的元素
        while (q.size() && q.back() <a[i]) q.pop_back();
        q.push_back(a[i]);
        // 输出当前窗口的最大值
        if (i >= k) {
            cout << q.front() << " ";
            // 如果窗口左边界的元素是最大值，则移除它
            if (a[i - k + 1] == q.front()) q.pop_front();
        }
    }

    return 0;
}

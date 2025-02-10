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

    // ���㻬�����ڵ���Сֵ
    for (int i = 1; i <= n; i++) {
        // �Ƴ����ڵ�ǰԪ�ص�Ԫ��
        while (q.size() && q.back() > a[i]) q.pop_back();
        q.push_back(a[i]);
        // �����ǰ���ڵ���Сֵ
        if (i >= k) {
            cout << q.front() << " ";
            // ���������߽��Ԫ������Сֵ�����Ƴ���
            if (a[i - k + 1] == q.front()) q.pop_front();
        }
    }
    cout << endl;

    q.clear();
    // ���㻬�����ڵ����ֵ
    for (int i = 1; i <= n; i++) {
        // �Ƴ�С�ڵ�ǰԪ�ص�Ԫ��
        while (q.size() && q.back() <a[i]) q.pop_back();
        q.push_back(a[i]);
        // �����ǰ���ڵ����ֵ
        if (i >= k) {
            cout << q.front() << " ";
            // ���������߽��Ԫ�������ֵ�����Ƴ���
            if (a[i - k + 1] == q.front()) q.pop_front();
        }
    }

    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
    int a;
    int b;
    int w;
} e[M];

int dist[N];
int back[N];
int n, m, k;

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(back, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back[a] + w);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d", dist[n]);
    return 0;
}
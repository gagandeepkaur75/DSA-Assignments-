#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int find(int p[], int x) {
    if (p[x] == x) return x;
    return p[x] = find(p, p[x]);
}

void uni(int p[], int a, int b) {
    p[find(p, b)] = find(p, a);
}

int main() {
    int n, e;
    cin >> n >> e;

    Edge a[50];
    for (int i = 0; i < e; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;

    sort(a, a + e, [](Edge x, Edge y) { return x.w < y.w; });

    int p[20];
    for (int i = 0; i < n; i++)
        p[i] = i;

    for (int i = 0; i < e; i++) {
        int u = a[i].u, v = a[i].v;
        if (find(p, u) != find(p, v)) {
            cout << u << " " << v << " " << a[i].w << endl;
            uni(p, u, v);
        }
    }
}

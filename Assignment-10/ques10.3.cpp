#include <iostream>
using namespace std;

int g[20][20], vis[20], n;

void dfs(int v) {
    vis[v] = 1;
    cout << v << " ";
    for (int i = 0; i < n; i++)
        if (g[v][i] && !vis[i])
            dfs(i);
}

int main() {
    int e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    int start;
    cin >> start;

    dfs(start);
}

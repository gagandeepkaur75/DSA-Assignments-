#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int g[20][20] = {0};

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    int vis[20] = {0};
    queue<int> q;

    int start;
    cin >> start;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < n; i++) {
            if (g[x][i] && !vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

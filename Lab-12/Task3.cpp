 #include <iostream>
 using namespace std;
 int main() {
    const int INF = 1e9;
    int n = 6;
    int dist[6];
    bool used[6] = {};
    int parent[6];
    for (int i = 0; i < 6; i++) dist[i] = INF;
    int g[6][6] = {};
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            g[i][j] = INF;
    g[1][0] = g[0][1] = 4;
    g[1][2] = g[2][1] = 9;
    g[0][3] = g[3][0] = 8;
    g[2][3] = g[3][2] = 6;
    g[3][5] = g[5][3] = 4;
    g[5][4] = g[4][5] = 3;
    g[2][4] = g[4][2] = 14;
    dist[1] = 0;
    for (int i = 0; i < 6; i++) {
        int v = -1;
        for (int j = 0; j < 6; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        used[v] = true;
        for (int u = 0; u < 6; u++) {
            if (g[v][u] < INF && dist[v] + g[v][u] < dist[u]) {
                dist[u] = dist[v] + g[v][u];
                parent[u] = v;
            }
        }
    }
    int target = 4;
    int path[6], idx = 0;
    for (int v = target; v != 1; v = parent[v]) path[idx++] = v;
    path[idx++] = 1;
    for (int i = idx - 1; i >= 0; i--) {
        char c = 'A' + path[i];
        cout << c;
        if (i) cout << " ";
    }
    cout << "\n" << dist[target];
}
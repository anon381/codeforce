// DFS flood-fill in 3D grid starting from (level0,x,y) counting reachable '.' cells.
#include <bits/stdc++.h>
using namespace std;

void dfs(int h, int row, int col, vector<vector<vector<bool>>> &g, int &count) {
    if (h < 0 || h >= g.size() || row < 0 || row >= g[0].size() || col < 0 || col >= g[0][0].size())
        return;
    if (!g[h][row][col])
        return;

    g[h][row][col] = 0;
    ++count;

    dfs(h - 1, row, col, g, count);
    dfs(h + 1, row, col, g, count);
    dfs(h, row - 1, col, g, count);
    dfs(h, row + 1, col, g, count);
    dfs(h, row, col - 1, g, count);
    dfs(h, row, col + 1, g, count);
}

int main() {
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    vector<vector<vector<bool>>> g(k, vector<vector<bool>>(n, vector<bool>(m, 0)));

    for (int p = 0; p < k; p++) {
        for (int q = 0; q < n; q++) {
            string s;
            cin >> s;
            for (int r = 0; r < m; r++)
                g[p][q][r] = (s[r] == '.');
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;

    int count = 0;
    dfs(0, x, y, g, count);
    printf("%d\n", count);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void dfs(long node, long from, const vector<vector<bool>> &g, vector<bool> &visited, vector<long> &cycle) {
    if (visited[node]) return;
    visited[node] = 1;
    if (!cycle.empty()) return;

    for (long u = 0; u < g[node].size(); u++) {
        if (!g[node][u]) continue;
        if ((from >= 0) && g[u][from]) {
            cycle.push_back(1 + from);
            cycle.push_back(1 + node);
            cycle.push_back(1 + u);
            return;
        }
        if (visited[u]) continue;
        dfs(u, node, g, visited, cycle);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long n;
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n, 0));

    for (long p = 0; p < n; p++) {
        string s;
        cin >> s;
        for (long u = 0; u < n; u++) g[p][u] = s[u] - '0';
    }

    vector<long> cycle;
    vector<bool> visited(n, 0);

    for (long p = 0; p < n; p++) {
        if (visited[p]) continue;
        dfs(p, -1, g, visited, cycle);
        if (!cycle.empty()) break;
    }

    if (cycle.size() >= 3)
        cout << cycle[0] << " " << cycle[1] << " " << cycle[2] << "\n";
    else
        cout << "-1\n";

    return 0;
}

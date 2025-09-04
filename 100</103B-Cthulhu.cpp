#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
int totalVisited = 0;

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    ++totalVisited;
    for (int neighbor : edges[node]) {
        dfs(neighbor);
    }
}

int main() {
    int n, m; 
    scanf("%d %d", &n, &m);
    if (n != m) {
        puts("NO");
        return 0;
    }

    edges.resize(n + 1);
    visited.resize(n + 1, false);

    for (int p = 0; p < m; p++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);

    if (totalVisited < n) {
        puts("NO");
    } else {
        puts("FHTAGN!");
    }

    return 0;
}

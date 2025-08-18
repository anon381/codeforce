#include <bits/stdc++.h>
using namespace std;

void dfs(int64_t node, const vector<vector<pair<int64_t, int64_t>>> &g, vector<bool> &visited, vector<int64_t> &distance){
    if(visited[node]) return;
    visited[node] = true;

    for(int64_t p = 0; p < g[node].size(); p++){
        int64_t u = g[node][p].first;
        if(visited[u]) continue;
        distance[u] = distance[node] + g[node][p].second;
        dfs(u, g, visited, distance);
    }
}

int main(){
    int64_t n; scanf("%lld", &n);
    vector<vector<pair<int64_t, int64_t>>> g(n);
    int64_t total = 0;

    for(int64_t p = 1; p < n; p++){
        int64_t x, y, d; scanf("%lld %lld %lld", &x, &y, &d);
        --x; --y;
        g[x].push_back({y, d});
        g[y].push_back({x, d});
        total += 2 * d;
    }

    vector<bool> mark(n, false);
    vector<int64_t> dist(n, 0);
    dfs(0, g, mark, dist);

    int64_t maxDist = 0;
    for(int64_t p = 0; p < n; p++){
        maxDist = max(maxDist, dist[p]);
    }

    printf("%lld\n", total - maxDist);
    return 0;
}

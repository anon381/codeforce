// Runs Dijkstra shortest path from node 1 to node n in an undirected weighted graph.
// Prints one shortest path or -1 if target is unreachable.
#include <bits/stdc++.h>
using namespace std;

int main() {

    int64_t n, m; 
    scanf("%lld %lld\n", &n, &m);
    vector<vector<pair<int64_t, int64_t>>> g(n + 1);

    while(m--) {
        int64_t u, v, w; 
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u].push_back(pair<int64_t, int64_t>(v, w));
        g[v].push_back(pair<int64_t, int64_t>(u, w));
    }

    int64_t source(1), target(n);
    set<pair<int64_t, int64_t>> q;
    q.insert(pair<int64_t, int64_t>(0, source));

    vector<int64_t> dist(n + 1, -1);
    vector<int64_t> from(n + 1, -1); 
    from[0] = 0; 
    from[1] = 1;

    vector<bool> visited(n + 1, 0);

    while(!q.empty()) {
        pair<int64_t, int64_t> cur = *q.begin();
        q.erase(q.begin());

        int64_t distance = cur.first;
        int64_t vertex = cur.second;

        if(visited[vertex]) { continue; }
        visited[vertex] = true;

        for(int64_t p = 0; p < g[vertex].size(); p++) {
            pair<int64_t, int64_t> edge = g[vertex][p];
            int64_t u = edge.first;
            int64_t w = edge.second;
            if(visited[u]) { continue; }
            if(dist[u] < 0 || dist[u] > distance + w) {
                dist[u] = distance + w;
                q.insert(pair<int64_t, int64_t>(dist[u], u));
                from[u] = vertex;
            }
        }
    }

    if(dist[n] < 0) { 
        puts("-1"); 
    } 
    else {
        stack<int64_t> st; 
        st.push(n);
        do { st.push(from[st.top()]); } while(st.top() != from[st.top()]);
        while(!st.empty()) { printf("%lld ", st.top()); st.pop(); }
        puts("");
    }

    return 0;
}

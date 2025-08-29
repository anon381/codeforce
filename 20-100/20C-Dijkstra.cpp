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
// or in python id needed
/*
import heapq

def dijkstra(n, edges):
    # Build graph
    g = [[] for _ in range(n + 1)]
    for u, v, w in edges:
        g[u].append((v, w))
        g[v].append((u, w))

    source, target = 1, n
    dist = [-1] * (n + 1)
    from_node = [-1] * (n + 1)
    from_node[0] = 0
    from_node[1] = 1
    visited = [False] * (n + 1)

    # Priority queue: (distance, vertex)
    pq = []
    heapq.heappush(pq, (0, source))

    while pq:
        distance, vertex = heapq.heappop(pq)
        if visited[vertex]:
            continue
        visited[vertex] = True

        for u, w in g[vertex]:
            if visited[u]:
                continue
            if dist[u] < 0 or dist[u] > distance + w:
                dist[u] = distance + w
                heapq.heappush(pq, (dist[u], u))
                from_node[u] = vertex

    if dist[target] < 0:
        print(-1)
    else:
        path = []
        cur = target
        while cur != from_node[cur]:
            path.append(cur)
            cur = from_node[cur]
        path.append(cur)
        print(*reversed(path))


# Example usage:
n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]
dijkstra(n, edges)


*/

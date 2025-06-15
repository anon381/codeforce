// Uses DSU to replace redundant edges with needed ones to connect all components (outputs operations).
#include <bits/stdc++.h>
using namespace std;

long find(long x, vector<long> &v) {
    return (v[x] == x) ? x : (v[x] = find(v[x], v));
}

int main() {

    long n; 
    scanf("%ld", &n);
    
    vector<long> f(n + 1, 0); 
    for(long p = 1; p <= n; p++) { f[p] = p; }

    vector<pair<long, long>> rem;
    for(long p = 1; p < n; p++) {
        long x, y; 
        scanf("%ld %ld", &x, &y);
        long r = find(x, f); 
        long s = find(y, f);
        if(r == s) { 
            rem.push_back(make_pair(x, y)); 
        } 
        else { 
            f[s] = r; 
        }
    }

    vector<pair<long, long>> add;
    for(long p = 2; p <= n; p++) {
        if(find(p, f) == find(1, f)) { continue; }
        add.push_back(make_pair(find(p, f), 1));
        f[find(p, f)] = find(1, f);
    }

    printf("%ld\n", rem.size());
    for(long p = 0; p < rem.size(); p++) {
        printf("%ld %ld %ld %ld\n", rem[p].first, rem[p].second, add[p].first, add[p].second);
    }

    return 0;
}

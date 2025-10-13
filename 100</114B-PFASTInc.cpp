#include <bits/stdc++.h>
using namespace std;

vector<bool> getBinaryVector(long x) {
    vector<bool> v;
    while (x > 0) {
        v.push_back(x % 2);
        x /= 2;
    }
    return v;
}

int countOnes(vector<bool> v) {
    int cnt = 0;
    for (int p = 0; p < v.size(); p++) cnt += v[p];
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    map<string, int> nmp;
    vector<string> nmv(n);
    for (int p = 0; p < n; p++) {
        string x;
        cin >> x;
        nmp[x] = p;
        nmv[p] = x;
    }

    set<pair<int, int>> enset;
    for (int p = 0; p < m; p++) {
        string x, y;
        cin >> x >> y;
        int u = nmp[x], v = nmp[y];
        enset.insert({u, v});
        enset.insert({v, u});
    }

    set<string> clique;
    long B = (1 << n);
    for (long p = 1; p < B; p++) {
        vector<bool> bv = getBinaryVector(p);
        bool possible = true;

        for (int x = 0; x < bv.size() && possible; x++) {
            if (!bv[x]) continue;
            for (int y = x + 1; y < bv.size(); y++) {
                if (!bv[y]) continue;
                if (enset.count({x, y})) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            int cnt = countOnes(bv);
            if (cnt > (int)clique.size()) {
                clique.clear();
                for (int p = 0; p < bv.size(); p++) {
                    if (bv[p]) clique.insert(nmv[p]);
                }
            }
        }
    }

    cout << clique.size() << "\n";
    for (auto &name : clique) cout << name << "\n";

    return 0;
}

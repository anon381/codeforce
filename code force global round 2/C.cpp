#include <bits/stdc++.h>
using namespace std;

bool solve_case(const string& s) {
    int n = s.size();
    vector<int> z;
    for (int i = 0; i < n; ++i) if (s[i] == '0') z.push_back(i);
    if (z.empty()) return true;

    vector<char> canL(n, 0), canR(n, 0);
    for (int i : z) {
        canL[i] = (i == 0) || (s[i-1] == '0') || (i >= 2 && s[i-1] == '1' && s[i-2] == '0');
        canR[i] = (i == n-1) || (s[i+1] == '0') || (i + 2 < n && s[i+1] == '1' && s[i+2] == '0');
    }

    int m = (int)z.size();
    int idx = 0;
    while (idx < m) {
        int j = idx;
        while (j + 1 < m && z[j+1] == z[j] + 2 && s[z[j] + 1] == '1') ++j;

        int first = z[idx];
        int cur = (canL[first] ? 1 : 0) | (canR[first] ? 2 : 0);
        if (!cur) return false;

        for (int t = idx + 1; t <= j; ++t) {
            int i = z[t];
            int nxt = 0;
            if ((cur & 1) && canR[i]) nxt |= 2;
            if ((cur & 2) && canL[i]) nxt |= 1;
            cur = nxt;
            if (!cur) return false;
        }
        idx = j + 1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        cout << (solve_case(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}


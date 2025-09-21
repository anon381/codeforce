#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        int m = 2 * n;
        vector<int> a(m + 1, 0);
        vector<char> used(m + 1, 0);
        int cur = 1;
        for (int x = n; x >= 1; --x) {
            while (used[cur]) ++cur;
            int i = cur;
            int j = i + x;
            while (j <= m && used[j]) j += x;
            a[i] = a[j] = x;
            used[i] = used[j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}

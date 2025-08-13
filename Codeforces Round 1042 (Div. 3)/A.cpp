#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int ans = 0;
        while (true) {
            bool dec = false, inc = false;
            for (int i = 0; i < n; i++) if (a[i] > b[i]) dec = true;
            for (int i = 0; i < n; i++) if (a[i] < b[i]) inc = true;
            ans++;
            if (dec) {
                for (int i = 0; i < n; i++) if (a[i] > b[i]) { a[i]--; break; }
            }
            if (inc) {
                for (int i = 0; i < n; i++) if (a[i] < b[i]) { a[i]++; break; }
            }
            if (!dec) break;
        }
        cout << ans << "\n";
    }
}

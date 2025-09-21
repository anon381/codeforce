#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; 
    if (!(std::cin >> t)) return 0;

    while (t--) {
        int n; 
        std::cin >> n;
        int m = 2 * n;

        std::vector<int> a(m + 1, 0);
        std::vector<char> used(m + 1, 0);

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
            if (i > 1) std::cout << ' ';
            std::cout << a[i];
        }
        std::cout << '\n';
    }
    return 0;
}

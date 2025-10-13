#include <bits/stdc++.h>
using namespace std;

int main() {
    const long N = 1e5 + 7;
    vector<long> v(N, 0);

    long n;
    cin >> n;
    for (long p = 1; p <= n; p++) {
        long x, y;
        cin >> x >> y;
        long cnt = 0;

        for (long a = 1; a * a <= x; a++) {
            if (x % a != 0) continue;
            long b = x / a;

            if (v[a] < p - y) cnt++;
            v[a] = p;

            if (v[b] < p - y) cnt++;
            v[b] = p;
        }

        cout << cnt << "\n";
    }

    return 0;
}

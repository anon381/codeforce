#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y;
    cin >> N >> x >> y;

    int n = N / 2;
    if ((x == n || x == n + 1) && (y == n || y == n + 1))
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}

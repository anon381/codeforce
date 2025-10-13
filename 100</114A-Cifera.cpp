#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, m;
    cin >> k >> m;

    long long temp = k;
    int times = 0;

    while (temp < m) {
        temp *= k;
        times++;
    }

    if (temp == m)
        cout << "YES\n" << times;
    else
        cout << "NO\n";

    return 0;
}

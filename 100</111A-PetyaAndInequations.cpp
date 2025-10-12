#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    bool possible = true;
    vector<long long> numbers(n, 1);
    numbers[n - 1] = y - (n - 1);
    if (numbers[n - 1] <= 0) possible = false;

    long long sumOfSquares = 0;
    for (int p = 0; p < n; p++) sumOfSquares += numbers[p] * numbers[p];
    if (sumOfSquares < x) possible = false;

    if (possible) {
        for (int p = 0; p < n; p++) cout << numbers[p] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}

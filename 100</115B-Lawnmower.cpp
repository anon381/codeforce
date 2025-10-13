#include <bits/stdc++.h>
using namespace std;

long absLong(long x) { return x >= 0 ? x : -x; }

int main() {
    long rows, cols;
    cin >> rows >> cols;
    vector<string> m(rows);
    for (int p = 0; p < rows; p++) cin >> m[p];

    long rr = 0, cc = 0, res = 0;
    for (long row = 0; row < rows; row++) {
        long startCol = (row % 2) ? (cols - 1) : 0;
        long stepCol = (row % 2) ? -1 : 1;
        for (long col = startCol; col >= 0 && col < cols; col += stepCol) {
            if (m[row][col] == 'W') {
                long xdiff = absLong(cc - col);
                long ydiff = absLong(rr - row);
                res += xdiff + ydiff;
                rr = row;
                cc = col;
            }
        }
    }

    cout << res << "\n";
    return 0;
}

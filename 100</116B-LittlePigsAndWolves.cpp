#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);

    vector<string> array;
    string line;
    for (int k = 0; k < n; k++) {
        getline(cin, line);
        array.push_back(line);
    }

    int eligiblePigs = 0, eligibleWolves = 0;
    char currentCell;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            currentCell = array[row][col];
            if (currentCell == '.') continue;

            if (currentCell == 'P') {
                if ((row > 0 && array[row - 1][col] == 'W') ||
                    (row < n - 1 && array[row + 1][col] == 'W') ||
                    (col > 0 && array[row][col - 1] == 'W') ||
                    (col < m - 1 && array[row][col + 1] == 'W')) {
                    ++eligiblePigs;
                }
            }

            if (currentCell == 'W') {
                if ((row > 0 && array[row - 1][col] == 'P') ||
                    (row < n - 1 && array[row + 1][col] == 'P') ||
                    (col > 0 && array[row][col - 1] == 'P') ||
                    (col < m - 1 && array[row][col + 1] == 'P')) {
                    ++eligibleWolves;
                }
            }
        }
    }

    cout << min(eligiblePigs, eligibleWolves) << endl;
    return 0;
}

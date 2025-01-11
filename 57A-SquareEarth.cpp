#include <bits/stdc++.h>
using namespace std;

// This program determines the shortest travel distance between two points located on the border of a square.
// Each coordinate is converted to a unique position along the square's perimeter, then the minimal path is computed.

int main() {
    int n, x1, y1, x2, y2;
    scanf("%d %d %d %d %d\n", &n, &x1, &y1, &x2, &y2);

    // Convert the first point to its perimeter index
    int d1 = 0;
    if (y1 == 0) d1 = x1;
    else if (x1 == n) d1 = n + y1;
    else if (y1 == n) d1 = 3 * n - x1;
    else if (x1 == 0) d1 = 4 * n - y1;

    // Convert the second point to its perimeter index
    int d2 = 0;
    if (y2 == 0) d2 = x2;
    else if (x2 == n) d2 = n + y2;
    else if (y2 == n) d2 = 3 * n - x2;
    else if (x2 == 0) d2 = 4 * n - y2;

    // Find the shortest path by comparing both possible directions
    int clockwise = (8 * n + d1 - d2) % (4 * n);
    int counterclockwise = (8 * n + d2 - d1) % (4 * n);
    int shortest = min(clockwise, counterclockwise);
    printf("%d\n", shortest);

    return 0;
}
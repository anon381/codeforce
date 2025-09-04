
// Time Complexity     and 	Space Complexity
// 	O(1)	O(1)
    
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;

    const int queenOfSpades = 10;
    const int upperBound = 25;
    int ways[upperBound + 1] = {0};

    for (int k = queenOfSpades + 1; k <= queenOfSpades + 11; k++) {
        ways[k] = 4;
    }

    ways[2 * queenOfSpades] = 15;

    cout << ways[n] << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    long n = 0;
    cin >> n;
    for (int k = 0; k < n; k++) {
        if (k % 4 == 0) cout << "a";
        else if (k % 4 == 1) cout << "b";
        else if (k % 4 == 2) cout << "c";
        else cout << "d";
    }
    cout << "\n";
    return 0;
}

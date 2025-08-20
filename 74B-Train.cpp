#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; 
    cin >> n >> m >> k;

    string dirstr; 
    cin >> dirstr >> dirstr;  // reads the two words "to" + "head/tail"

    string state; 
    cin >> state;

    int dir = (dirstr == "head") ? -1 : 1;

    for (int p = 0; p < state.size(); p++) {
        if (state[p] == '1') {
            k += dir;
            if (k == 1 || k == n) { dir = -dir; }
            if (k == 1) { m = n; }
            else if (k == n) { m = 1; }
            else { m = k - dir; }
        } else {
            if (k > m && m != 1) { --m; }
            if (k < m && m != n) { ++m; }
            k += dir;
            if (k == 1 || k == n) dir = -dir;
        }

        if (k == m) {
            cout << "Controller " << (p + 1) << endl;
            return 0;
        }
    }

    cout << "Stowaway" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sup(n + 1);

    for (int k = 1; k <= n; k++) cin >> sup[k];

    int total = 0;
    for (int k = 1; k <= n; k++) {
        int temp = 1, boss = sup[k];
        while (boss != -1) {
            boss = sup[boss];
            ++temp;
        }
        total = max(total, temp);
    }

    cout << total << "\n";
    return 0;
}

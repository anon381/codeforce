#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    long k, a, b; 
    cin >> k >> a >> b;
    string s; 
    cin >> s;

    if (s.size() < k * a || s.size() > k * b) {
        cout << "No solution" << endl; 
        return 0;
    }

    long avg = s.size() / k;
    long add = s.size() % k;
    long cnt(0);

    for (long p = 0; p < (long)s.size(); p++) {
        cout << s[p]; 
        ++cnt;
        if (cnt >= avg + (add > 0)) {
            cout << endl; 
            cnt = 0; 
            --add;
        }
    }

    return 0;
}

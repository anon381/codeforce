#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second;
    getline(cin, first);
    getline(cin, second);

    int comparison = 0;
    for (int k = 0; k < first.size(); ++k) {
        char a = tolower(first[k]);
        char b = tolower(second[k]);
        if (a < b) { comparison = -1; break; }
        if (a > b) { comparison = 1; break; }
    }

    cout << comparison << "\n";
    return 0;
}

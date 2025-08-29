#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 5;
    map<string, int> rem;
    map<string, vector<string>> pref;

    vector<string> temp;

    temp = {"S", "M", "L", "XL", "XXL"};
    pref["S"] = temp;

    temp = {"M", "L", "S", "XL", "XXL"};
    pref["M"] = temp;

    temp = {"L", "XL", "M", "XXL", "S"};
    pref["L"] = temp;

    temp = {"XL", "XXL", "L", "M", "S"};
    pref["XL"] = temp;

    temp = {"XXL", "XL", "L", "M", "S"};
    pref["XXL"] = temp;

    int t;
    scanf("%d", &t); rem["S"] = t;
    scanf("%d", &t); rem["M"] = t;
    scanf("%d", &t); rem["L"] = t;
    scanf("%d", &t); rem["XL"] = t;
    scanf("%d", &t); rem["XXL"] = t;

    int n; 
    scanf("%d", &n);

    for (int p = 0; p < n; p++) {
        string s; 
        cin >> s;
        for (int q = 0; q < N; q++) {
            string cp = pref[s][q];
            if (rem[cp] > 0) {
                cout << cp << endl;
                --rem[cp];
                break;
            }
        }
    }

    return 0;
}

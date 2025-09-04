#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    const int minLevel = 100;
    const double eps = 0.001;

    int n, m;
    double k;
    cin >> n >> m >> k;

    map<string, int> skillMap;

    for (int p = 0; p < n; p++) {
        string currentSkill;
        int currentLevel;
        cin >> currentSkill >> currentLevel;

        if (k * currentLevel >= minLevel) {
            skillMap.insert({currentSkill, static_cast<int>(eps + k * currentLevel)});
        }
    }

    for (int p = 0; p < m; p++) {
        string currentSkill;
        cin >> currentSkill;

        if (skillMap.find(currentSkill) == skillMap.end()) {
            skillMap.insert({currentSkill, 0});
        }
    }

    vector<string> skillVec;
    for (auto& pair : skillMap) {
        skillVec.push_back(pair.first);
    }

    sort(skillVec.begin(), skillVec.end());

    cout << skillVec.size() << endl;
    for (auto& skill : skillVec) {
        cout << skill << " " << skillMap[skill] << endl;
    }

    return 0;
}

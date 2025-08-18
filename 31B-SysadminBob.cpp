#include <bits/stdc++.h>

using namespace std;

int main() {

    string db; cin >> db;
    bool sol(true);
    vector<string> dv;
    string cur; bool gat(false);

    for(long p = 0; p < db.size(); p++) {
        cur += db[p];
        if(db[p] == '@') {
            if(gat || (cur.size() == 1) || (p + 2 > db.size())) { 
                sol = false; 
                break;
            } 
            gat = true;
        }
        else if(gat) {
            dv.push_back(cur); 
            cur = ""; 
            gat = false;
        }
    }

    if(dv.size() > 0 && cur.size() > 0 && !gat) {
        dv.back() += cur;
    }
    else if(dv.size() <= 0) {
        sol = false;
    }

    if(sol) {
        for(long p = 0; p < dv.size(); p++) {
            cout << dv[p] << ((p + 1 < dv.size()) ? "," : "\n");
        }
    }
    else {
        cout << "No solution" << endl;
    }

    return 0;
}

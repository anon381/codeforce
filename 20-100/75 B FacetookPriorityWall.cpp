#include <bits/stdc++.h>
using namespace std;

struct str {
    string name; 
    long pr;
};

bool comp(str a, str b) {
    if (a.pr > b.pr) return true;
    else if (a.pr == b.pr && a.name < b.name) return true;
    return false;
}

int main() {
    string myname; 
    getline(cin, myname);

    string sn; 
    getline(cin, sn);

    long n(0); 
    for (long p = 0; p < sn.size(); p++) {
        n = 10 * n + (sn[p] - '0');
    }

    map<string, long> pm;

    while (n--) {
        string s; 
        getline(cin, s);
        string from(""), to("");
        long score(0);

        long ind(0); 
        while (s[ind] != ' ') { 
            from += s[ind]; 
            ++ind; 
        }
        ++ind;

        if (s[ind] == 'p') { ind += 10; score = 15; }
        else if (s[ind] == 'c') { ind += 13; score = 10; }
        else if (s[ind] == 'l') { ind += 6; score = 5; }

        while (s[ind] != '\'') { 
            to += s[ind]; 
            ++ind; 
        }

        if (from == myname) { pm[to] += score; }
        else if (to == myname) { pm[from] += score; }
        else { pm[to] += 0; pm[from] += 0; } // ensure they are in the map
    }

    vector<str> v;
    for (map<string, long>::iterator it = pm.begin(); it != pm.end(); it++) {
        str x; 
        x.name = it->first; 
        x.pr = it->second; 
        v.push_back(x);
    }

    sort(v.begin(), v.end(), comp);

    for (long p = 0; p < v.size(); p++) {
        cout << v[p].name << endl;
    }

    return 0;
}

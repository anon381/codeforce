#include <bits/stdc++.h>
using namespace std;

int main() {

    string s; cin >> s;
    string t;
    long ind(0);
    bool hasAt(false);

    while(ind < s.size()){
        if((ind > 0) && (ind + 3 < s.size() && s[ind] == 'd' && s[ind + 1] == 'o' && s[ind + 2] == 't')){
            t += '.';
            ind += 3;
        }
        else if((!hasAt) && (ind > 0) && (ind + 2 < s.size() && s[ind] == 'a' && s[ind + 1] == 't')){
            t += '@';
            hasAt = true;
            ind += 2;
        }
        else{
            t += s[ind];
            ++ind;
        }
    }

    cout << t << endl;
    return 0;
}

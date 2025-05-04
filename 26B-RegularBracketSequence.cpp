#include <bits/stdc++.h>
using namespace std;

int main() {

    string input; 
    getline(cin, input);

    long unmatched(0), matched(0);

    for(int k = 0; k < input.size(); k++) {
        if(input[k] == '(') { ++unmatched; }
        else if(input[k] == ')' && unmatched > 0) { --unmatched; ++matched; }
    }

    cout << 2 * matched << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {

    string input; 
    getline(cin, input);
    int output(0);

    for(size_t length = input.size() - 1; length >= 1; length--) {
        if(output > 0) { break; }
        set<string> present;

        for(size_t start = 0; start < input.size() - length + 1; start++) {
            string current = input.substr(start, length);
            if(present.find(current) == present.end()) { 
                present.insert(current); 
            } 
            else { 
                output = length; 
                break; 
            }
        }
    }

    cout << output << endl;

    return 0;
}

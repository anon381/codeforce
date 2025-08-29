#include <bits/stdc++.h>
using namespace std;

// This code scans the input string to see if the letters of 'hello' appear in order, possibly with other letters in between.
// It advances through the input, matching each character of 'hello' as it finds them.

int main() {
    const string target = "hello";
    string input;
    getline(cin, input);
    int match = 0;
    for (char c : input) {
        if (c == target[match]) match++;
        if (match == target.size()) break;
    }
    cout << (match == target.size() ? "YES" : "NO") << endl;
    return 0;
}
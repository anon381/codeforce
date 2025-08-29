#include <bits/stdc++.h>
using namespace std;

int countVowels(const string &line) {
    int cnt = 0;
    for (char ch : line) {
        char c = tolower(ch);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    string currentLine;
    bool output = true;

    getline(cin, currentLine);
    if (countVowels(currentLine) != 5) output = false;

    getline(cin, currentLine);
    if (countVowels(currentLine) != 7) output = false;

    getline(cin, currentLine);
    if (countVowels(currentLine) != 5) output = false;

    puts(output ? "YES" : "NO");
    return 0;
}

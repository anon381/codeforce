#include <bits/stdc++.h>
using namespace std;

int main() {
    string question;
    getline(cin, question);

    for (int k = question.size() - 1; k >= 0; k--) {
        char current = tolower(question[k]);
        if (!(current >= 'a' && current <= 'z')) continue;

        if (current == 'a' || current == 'e' || current == 'i' ||
            current == 'o' || current == 'u' || current == 'y') {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        break;
    }
    return 0;
}

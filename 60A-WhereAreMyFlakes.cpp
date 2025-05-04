// Narrows possible box interval based on directional hints; outputs count or -1.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n(0), m(0);
    scanf("%d %d\n", &n, &m);

    int leftBoundary(1), rightBoundary(n);

    while (m--) {
        string hint;
        getline(cin, hint);

        int currentBox(0), index(hint.size() - 1);

        while (hint[index] != ' ') --index;
        while (++index < hint.size()) currentBox = 10 * currentBox + (hint[index] - '0');

        if (hint.find("left") != string::npos && rightBoundary > currentBox - 1) {
            rightBoundary = currentBox - 1;
        } else if (hint.find("right") != string::npos && leftBoundary < currentBox + 1) {
            leftBoundary = currentBox + 1;
        }
    }

    if (rightBoundary < leftBoundary) {
        puts("-1");
    } else {
        cout << rightBoundary - leftBoundary + 1 << endl;
    }

    return 0;
}

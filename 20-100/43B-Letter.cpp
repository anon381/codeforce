#include <bits/stdc++.h>
using namespace std;

int main() {

    const int N = 26;
    vector<int> small(N, 0);
    vector<int> large(N, 0);

    string input; 
    getline(cin, input);
    for (int k = 0; k < input.size(); k++) {
        if ('a' <= input[k] && input[k] <= 'z') {
            ++small[input[k] - 'a'];
        }
        if ('A' <= input[k] && input[k] <= 'Z') {
            ++large[input[k] - 'A'];
        }
    }

    string message; 
    getline(cin, message);
    for (int k = 0; k < message.size(); k++) {
        if ('a' <= message[k] && message[k] <= 'z') {
            --small[message[k] - 'a'];
        }
        if ('A' <= message[k] && message[k] <= 'Z') {
            --large[message[k] - 'A'];
        }
    }

    string output = "YES";
    for (int k = 0; k < N; k++) {
        if (small[k] < 0 || large[k] < 0) {
            output = "NO";
            break;
        }
    }

    cout << output << endl;

    return 0;
}

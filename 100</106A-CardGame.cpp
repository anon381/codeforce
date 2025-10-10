#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    char trump;
    scanf("%c\n", &trump);

    string input;
    getline(cin, input);
    string output = "NO";

    map<char, int> value;
    value['6'] = 6;
    value['7'] = 7;
    value['8'] = 8;
    value['9'] = 9;
    value['T'] = 10;
    value['J'] = 11;
    value['Q'] = 12;
    value['K'] = 13;
    value['A'] = 14;

    if (input[1] == trump && input[4] != trump) {
        output = "YES";
    } else if (input[1] == input[4] && value[input[0]] > value[input[3]]) {
        output = "YES";
    }

    cout << output << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char,int> count;
    count['A'] = 0;
    count['B'] = 0;
    count['C'] = 0;

    for (int k = 0; k < 3; k++) {
        string temp; 
        getline(cin, temp);
        if (temp[1] == '<') {
            ++count[temp[2]];
        } else {
            ++count[temp[0]];
        }
    }

    if (count['A'] == 1 && count['B'] == 1 && count['C'] == 1) {
        puts("Impossible");
    } else {
        if (count['A'] == 0) printf("A");
        else if (count['B'] == 0) printf("B");
        else if (count['C'] == 0) printf("C");

        if (count['A'] == 1) printf("A");
        else if (count['B'] == 1) printf("B");
        else if (count['C'] == 1) printf("C");

        if (count['A'] == 2) printf("A");
        else if (count['B'] == 2) printf("B");
        else if (count['C'] == 2) printf("C");
    }
    puts("");

    return 0;
}

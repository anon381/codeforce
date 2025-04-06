// Time Complexity: O(1)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

int main(){
    string line; getline(cin, line);
    int separator = line.find('.');
    string integerPart = line.substr(0,separator);
    char firstDecimal = line[separator + 1];

    if(integerPart[separator - 1] == '9'){
        integerPart = "GOTO Vasilisa.";
    }
    else if(firstDecimal >= '5'){
        ++integerPart[separator - 1];
    }
    cout << integerPart << endl;
    return 0;
}
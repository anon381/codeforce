// Formats a digit string into groups: leading 3 if odd length else 2, then groups of 2 separated by dashes.
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n(0); 
    scanf("%d\n", &n);
    
    string number; 
    getline(cin, number);

    if(number.size() <= 3) {
        cout << number << endl;
    } 
    else {
        int index(0);

        if(number.size() % 2) {
            cout << number.substr(0, 3); 
            index = 3;
        } 
        else {
            cout << number.substr(0, 2); 
            index = 2;
        }

        while(index < number.size()) {
            cout << "-";
            cout << number.substr(index, 2);
            index += 2;
        }
        cout << endl;
    }

    return 0;
}

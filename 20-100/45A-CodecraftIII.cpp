#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 12;
    vector<string> months(N);
    months[0] = "January";   months[1] = "February"; months[2] = "March"; 
    months[3] = "April";     months[4] = "May";      months[5] = "June"; 
    months[6] = "July";      months[7] = "August";   months[8] = "September"; 
    months[9] = "October";   months[10] = "November"; months[11] = "December"; 

    string current; 
    getline(cin, current);

    int start(0);
    for (int p = 0; p < N; p++) {
        if (months[p] == current) {
            start = p; 
            break;
        }
    }

    int wait; 
    cin >> wait;
    cout << months[(start + wait) % N] << endl;

    return 0;
}

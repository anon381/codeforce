#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    scanf("%d\n", &n);

    map<string, int> scores;
    for (int k = 0; k < n; k++) {
        char name[20]; 
        scanf("%s", name);

        int temp(0), total(0);
        scanf("%d", &temp); total += 100 * temp;
        scanf("%d", &temp); total -= 50 * temp;

        for (int p = 0; p < 5; p++) {
            scanf("%d", &temp);
            total += temp;
        }
        scanf("\n");

        scores.insert(make_pair(string(name), total));
    }

    map<string, int>::iterator myIter = scores.begin();
    string roomLeader = myIter->first;
    int maxScore = myIter->second;

    for (myIter = scores.begin(); myIter != scores.end(); myIter++) {
        if ((myIter->second) > maxScore) {
            roomLeader = myIter->first;
            maxScore = myIter->second;
        }
    }

    cout << roomLeader << endl;
}

#include <bits/stdc++.h>
using namespace std;

bool firstWins(long n, long m, long k) {
    long mn = (m < n) ? m : n;
    if (mn % (k + 1) == 0) {
        return true;
    } else if (k == 1 || (mn / (k + 1)) % 2 == 0) {
        return (m % 2) != (n % 2);
    } else {
        return (m % 2) == (n % 2);
    }
}

int main() {
    ifstream instream("input.txt");
    FILE *outputFile = fopen("output.txt", "w");

    long t, k;
    instream >> t >> k;

    while (t--) {
        long n, m;
        instream >> n >> m;
        fputs(firstWins(n, m, k) ? "+\n" : "-\n", outputFile);
    }

    instream.close();
    fclose(outputFile);

    return 0;
}

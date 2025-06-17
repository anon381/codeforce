// Counts numbers in [1..n] with exactly two distinct prime divisors (almost primes).
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n(0); 
    scanf("%d\n", &n);

    bool *primes = new bool[n + 1];
    primes[0] = 0; primes[1] = 0;
    for(int k = 2; k <= n; k++) { primes[k] = 1; }

    for(int k = 2; k <= sqrt(n); k++) {
        if(!primes[k]) { continue; }
        for(int m = 2 * k; m <= n; m += k) { primes[m] = 0; }
    }

    vector<int> primesVector;
    for(int k = 2; k <= n; k++) {
        if(primes[k]) { primesVector.push_back(k); }
    }

    int almostPrimeCount(0);
    for(int k = 2; k <= n; k++) {
        int divisors(0);
        for(int p = 0; p < primesVector.size(); p++) {
            if(k % primesVector[p] == 0) { ++divisors; }
        }
        if(divisors == 2) { ++almostPrimeCount; }
    }

    printf("%d\n", almostPrimeCount);

    delete[] primes;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
// Determines the winner of the Beaver Game based on divisibility and game constraints.

int main(){

    long n, m, k; scanf("%ld %ld %ld\n", &n, &m, &k);
    if(n % 2 == 0){puts("Marsel"); return 0;}
    else{
        // Check for possible winning moves
        bool possible(0);
        for(long p = 1; p * p <= m; p++){
            // Skip if p is not a divisor of m
            if(m % p > 0){continue;}
            // Check both divisors for the winning condition
            if((k <= (m / p) && p > 1) || ((k <= p) && (m / p > 1)) ){possible = 1; break;}
        }

        puts(possible ? "Timur" : "Marsel");
    }

    return 0;
}
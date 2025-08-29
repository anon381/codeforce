// Time Complexity: O(log min(a, b))
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
// Compares two train lengths after reducing by their greatest common divisor and prints the result.

long gcd(long p, long q){
    // Recursively compute the greatest common divisor
    return p % q ? gcd(q, p % q) : q;
}

int main(){
    long a, b; scanf("%ld %ld", &a, &b);
    // Reduce a and b by their greatest common divisor
    long g = gcd(a, b);
    a /= g; b /= g;
    // If a and b differ by 1, print "Equal"
    if(a == b - 1 || b == a - 1){puts("Equal");}
    // If a is less than b, print "Dasha"
    else if(a < b){puts("Dasha");}
    // If a is greater than b, print "Masha"
    else if(a > b){puts("Masha");}
    return 0;
}
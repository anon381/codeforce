#include <bits/stdc++.h>
using namespace std;

// Calculates the minimum number of intervals needed to cover all presents, given their positions and a fixed interval length.
// Uses arithmetic to determine the number of intervals between presents.

int main(){

    long n, k; scanf("%ld %ld", &n, &k);
    long c; scanf("%ld", &c);
    long last(0), cnt(0);
    for(long p = 0; p < c; p++){
        long x; scanf("%ld", &x);
        long dur = x - last;
        cnt += 1 + (dur - 1) / k;
        last = x;
    }

    cnt += (n - last) / k;
    printf("%ld\n", cnt);

    return 0;
}
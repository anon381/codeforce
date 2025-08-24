#include <bits/stdc++.h>
using namespace std;

int main() {

    long n; 
    scanf("%ld\n", &n);

    long zeros(0), ones(0), twos(0);

    while (n--) {
        long t; 
        scanf("%ld", &t);
        if (t % 3 == 0) {
            ++zeros;
        }
        else if (t % 3 == 1) {
            ++ones;
        }
        else if (t % 3 == 2) {
            ++twos;
        }
    }

    long total = (zeros / 2) + min(ones, twos);
    printf("%ld\n", total);

    return 0;
}

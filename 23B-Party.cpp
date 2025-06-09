// For each test: given n, prints max number of full groups of size >=2 after removing two people (n-2) if n>2 else 0.
#include <bits/stdc++.h>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        printf("%ld\n", n > 2 ? (n - 2) : 0);
    }

    return 0;
}

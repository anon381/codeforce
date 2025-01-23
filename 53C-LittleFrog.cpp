#include <bits/stdc++.h>
using namespace std;

// Prints a sequence of numbers from 1 to n, alternating between the lowest and highest remaining values.
// This creates a zigzag pattern for the frog's jumps.

int main(){

    long n; scanf("%ld\n", &n);
    long x(1), y(n);
    for(long p = 0; p < n; p++){
        if(p % 2 == 0){printf("%ld ", x++);}
        else{printf("%ld ", y--);}
    }
    puts("");

    return 0;
}
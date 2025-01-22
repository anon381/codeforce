#include <bits/stdc++.h>
using namespace std;

// Reads a sequence of numbers and counts the occurrences of each value (1-3).
// Outputs the sum of the two middle counts after sorting, representing a specific problem's requirement.

int main(){

    long count[4] = {0};

    long n; scanf("%ld", &n);
    for(long p = 0; p < n; p++){int temp; scanf("%d", &temp); ++count[temp];}
    sort(count, count + 4);
    printf("%ld\n", count[1] + count[2]);

    return 0;
}
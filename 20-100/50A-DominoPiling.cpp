// Added for competitive programming convenience
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using namespace tsd;

// Calculates the maximum number of dominoes that can fit on an M x N board.
// Each domino covers two squares, so the answer is simply (M * N) / 2.

int main(){
    int M = 0, N = 0; scanf("%d %d\n",&M, &N);
    printf("%d\n", M * N / 2);
    return 0;
}
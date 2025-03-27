// Finds the maximum value in a list of frame sizes.
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Read input values
    long n, m, a, b; scanf("%ld %ld %ld %ld\n", &n, &m, &a, &b);
    --a; --b; 
    int ans(0);

    // Check if all values are in the same group or at the edges
    if(m == 1 || a / m == b / m || (a % m == 0 && (b % m == m - 1 || b == n - 1))){ans = 1;}
    // Check if values are at the edges or in adjacent groups
    else if(a % m == 0 || b % m == m - 1 || b == n - 1 || (m+b%m-a%m+1==b-a+1) || a%m==b%m+1){ans = 2;}
    // Otherwise, it takes 3 moves
    else{ans = 3;}

    // Output the result
    printf("%d\n", ans);

    return 0;
}
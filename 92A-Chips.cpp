// Calculates the remaining chips after distributing them among players.
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <cstdio>
#include <cmath>
 #include <bits/stdc++.h>
 
 using namespace std;

int main(){
    // Read number of players and chips
    int n, m; scanf("%d %d", &n, &m);
    // Calculate the remaining chips after full rounds
    m %= (n * (n + 1) / 2);
    // Find the largest k such that sum 1+2+...+k <= m
    int x = (sqrt(8 * m + 1) - 1)/ 2.0;
    // Output the remaining chips after distributing to k players
    printf("%d\n", m - x * (x + 1) / 2);
    return 0;
}
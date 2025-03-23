// Calculates the remaining chips after distributing them among players.
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <cstdio>
#include <cmath>
 #include <bits/stdc++.h>
 
 using namespace std;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    m %= (n * (n + 1) / 2);
    int x = (sqrt(8 * m + 1) - 1)/ 2.0;
    printf("%d\n", m - x * (x + 1) / 2);
    return 0;
}
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
// Computes the total number of toy soldiers in the army based on input n.

int main(){
    int n;
    // Read the number of soldiers
    scanf("%d", &n);
    // Calculate and print the total number of toy soldiers
    printf("%d\n", 3 * n / 2);
    return 0;
}
// Computes the minimum time to transport people using cableways.
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Read the number of people for each cableway (red, green, blue)
    int r(0), g(0), b(0); scanf("%d %d %d", &r, &g, &b);

    // Calculate the minimum number of trips for each cableway
    r = (r + 1) / 2; g = (g + 1) / 2; b = (b + 1) / 2;

    int output(0);
    // Determine which cableway takes the longest and calculate total time
    if(b >= g && b >= r){
        // Blue cableway takes the longest
        output = 30 + 3 * b - 1;
    }
    else if(g >= r){
        // Green cableway takes the longest
        output = 30 + 3 * g - 2;
    }
    else{
        // Red cableway takes the longest
        output = 30 + 3 * r - 3;
    }

    // Output the minimum total time
    printf("%d\n", output);

    return 0;
}
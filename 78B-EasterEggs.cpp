#include <bits/stdc++.h>

using namespace std;
// Generates a color sequence for Easter eggs, repeating the pattern as needed for the given length.

int main(){

    const char array[7] = {'R','O','Y','G','B','I','V'};
    int n(0); scanf("%d", &n);
    // Print the first three colors
    for(int k = 0; k < 3; k++){printf("%c", array[k]);}
    // Print the remaining colors, cycling through the last four
    for(int k = 3; k < n; k++){printf("%c", array[3 + k%4]);}
    puts("");
    
    return 0;
}
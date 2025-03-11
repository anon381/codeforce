// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;
// Calculates the total number of contiguous segments of equal values in an array.

int main(){

    long n(0); scanf("%ld", &n);

    long current(0), previous(0); scanf("%ld", &previous);
    long long total(0), count(1);
    --n;

    // Loop through the array, counting contiguous segments of equal values
    while(n--){
        // Read the next value
        scanf("%ld", &current);
        // If the value is the same as previous, increment count
        if(current == previous){++count;}
        // If the value changes, add the segment's contribution to total and reset count
        else{total += count * (count + 1) / 2; count = 1;}
        // Update previous value
        previous = current;
    }
    // Add the last segment's contribution to total
    total += count * (count + 1) / 2;

    printf("%lld\n", total);
    return 0;
}
// Determines the minimum number of moves to arrange people in a queue.
// Time Complexity: O(n log n)
// Space Complexity: O(n)
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Read the number of people in the queue
    long n; scanf("%ld", &n);
    // Store each person's value and their original position
    vector<pair<long, long>> a(n); 
    for(long p = 0; p < n; p++){
        scanf("%ld", &a[p].first);
        a[p].second = p; // Save original index
    }
    // Sort people by their value
    sort(a.begin(), a.end());
    long mx(-1); // Track the maximum index seen so far
    vector<long> f(n); 
    // Calculate the minimum moves for each person
    for(long p = 0; p < n; p++){
        // If current index is greater than max, set to -1, else calculate moves
        f[a[p].second] = (a[p].second > mx) ? (-1) : (mx - a[p].second - 1);
        // Update max index
        mx = (mx > a[p].second) ? mx : a[p].second;
    }

    // Output the result for each person
    for(long p = 0; p < n; p++){
        printf("%ld ", f[p]);
    }
    puts("");

    return 0;
}
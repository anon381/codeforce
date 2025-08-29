// Time Complexity: O(n log n) (due to sorting)
// Space Complexity: O(n)
#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;
// Distributes scores among participants based on input parameters and sorting logic.

int main(){

    const long N = 10;
    long n; scanf("%ld", &n);
    long a, b; scanf("%ld %ld", &a, &b);
    // If a and b are equal, assign 1 to first a participants, 2 to the rest
    if(a == b){for(long p = 0; p < n; p++){printf("%ld ", (p < a) ? 1L : 2L);}}
    else{
    // Create a vector of vectors to group positions by input value
    vector<vector<long> > v(N);
    // For each participant, read their value and store their position
        for(long p = 0; p < n; p++){long x; scanf("%ld", &x); v[x].push_back(p);}
    // Prepare the result vector
    vector<long> s(n);
        long x(a), y(b);
    // If a > b, assign 1 to the lowest values first
        if(a > b){
            for(long p = 0; p < N; p++){
        // For each position with value p, assign 1 if x > 0, else 2
                for(long u = 0; u < v[p].size(); u++){
                    long pos = v[p][u];
                    s[pos] = (x > 0) ? 1 : 2;
                    --x;
                }
            }
        }
    // If a < b, assign 1 to the highest values first
        else{
            for(long p = N - 1; p >= 0; p--){
        // For each position with value p, assign 1 if x > 0, else 2
                for(long u = 0; u < v[p].size(); u++){
                    long pos = v[p][u];
                    s[pos] = (x > 0) ? 1 : 2;
                    --x;
                }
            }
        }

    // Print the assigned values for all participants
        for(long p = 0; p < n; p++){printf("%ld ", s[p]);}
    }

    puts("");

    return 0;
}
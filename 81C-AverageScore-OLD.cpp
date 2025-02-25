#include <bits/stdc++.h>

using namespace std;
// Sorts and assigns values to a sequence based on input parameters.
int main(){

    long n; scanf("%ld", &n);
    long a, b; scanf("%ld %ld", &a, &b);
    // Read n values into vector f, storing both value and original index
    vector<pair<long, long> > f(n);
    for(long p = 0; p < n; p++){
        scanf("%ld", &f[p].first);
        f[p].second = p;
    }
    // Sort f in ascending order if a > b, descending if a < b
    if(a > b){
        sort(f.begin(), f.end());
    }
    else if(a < b){
        sort(f.rbegin(), f.rend());
    }

    vector<long> s(n);
    // Assign values to s based on sorted order and threshold a
    for(long p = 0; p < n; p++){
        s[f[p].second] = 1 + (p >= a);
    }
    // Output the result
    for(long p = 0; p < n; p++){
        printf("%ld ", s[p]);
    }
    puts("");

    return 0;
}
// Time Complexity: O(n log n)
// Space Complexity: O(n)
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){

    long n; scanf("%ld", &n);
    vector<pair<long, long>> a(n); 
    for(long p = 0; p < n; p++){scanf("%ld", &a[p].first); a[p].second = p;}
    sort(a.begin(), a.end());
    long mx(-1);
    vector<long> f(n); 
    for(long p = 0; p < n; p++){
        f[a[p].second] = (a[p].second > mx) ? (-1) : (mx - a[p].second - 1);
        mx = (mx > a[p].second) ? mx : a[p].second;
    }

    for(long p = 0; p < n; p++){printf("%ld ", f[p]);}
    puts("");

    return 0;
}
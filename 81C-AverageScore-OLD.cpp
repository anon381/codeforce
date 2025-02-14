#include <bits/stdc++.h>

using namespace std;
int main(){

    long n; scanf("%ld", &n);
    long a, b; scanf("%ld %ld", &a, &b);
    vector<pair<long, long> > f(n); for(long p = 0; p < n; p++){scanf("%ld", &f[p].first); f[p].second = p;}
    if(a > b){sort(f.begin(), f.end());}
    else if(a < b){sort(f.rbegin(), f.rend());}

    vector<long> s(n);
    for(long p = 0; p < n; p++){s[f[p].second] = 1 + (p >= a);}
    for(long p = 0; p < n; p++){printf("%ld ", s[p]);}
    puts("");

    return 0;
}
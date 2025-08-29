// Calculates the minimum number of coins needed for a robbery scenario.
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    // Read n (number of boxes), m (number of coins per box), k (number of robbers)
    ll n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
    // If n is even, output 0 (no coins needed)
    if(n % 2 == 0){
        puts("0");
    }
    else{
        // Calculate minimum coins needed for odd n
        ll mn(k * (m  / ((n + 1) / 2)));
        // Loop through each box
        for (ll p = 0; p < n; p++){
            ll x; scanf("%lld", &x);
            // If box index is even, update minimum coins
            if(p % 2 == 0){
                mn = (mn < x) ? mn : x;
            }
        }
        // Output the result
        printf("%lld\n", mn);
    }

    return 0;
}
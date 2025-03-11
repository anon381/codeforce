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

    while(n--){
        scanf("%ld", &current);
        if(current == previous){++count;}
        else{total += count * (count + 1) / 2; count = 1;}
        previous = current;
    }
    total += count * (count + 1) / 2;

    printf("%lld\n", total);
    return 0;
}